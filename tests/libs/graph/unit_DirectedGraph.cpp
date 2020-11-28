//
// Created by nolasco on 14/05/20.
//

#define CATCH_CONFIG_MAIN
#include <catch2/single_include/catch2/catch.hpp>

#include "constants.h"
#include "interface/graph/DirectedGraph.h"

SCENARIO("Addition of edge directed graph", "[DirectedGraph]") {

  GIVEN("A network of stalkers") {
    DirectedGraph<uint8_t, std::string, uint8_t> stalkerNetwork;
    stalkerNetwork.addNode(constants::person1Id, constants::person1Name);
    stalkerNetwork.addNode(constants::person2Id, constants::person2Name);
    stalkerNetwork.addNode(constants::person3Id, constants::person3Name);
    REQUIRE(stalkerNetwork.addEdge(constants::validLink12, constants::brotherhood));

    WHEN("a second edge with the same origin and destination is added") {
      const auto invalidInsertion = stalkerNetwork.addEdge(constants::invalidLink, constants::acquaintance);
      THEN("the operation fails due to looping connection") {
        REQUIRE_FALSE(invalidInsertion);
      }
    }

    WHEN("a second edge with the same id is added") {
      const auto insertionWithSameId = stalkerNetwork.addEdge(constants::validLink12, constants::acquaintance);
      THEN("the operation fails due to repeated id") {
        REQUIRE_FALSE(insertionWithSameId);
      }
    }

    WHEN("an edge is added with an invalid origin or destination") {
      const auto insertionWithInvalidId = stalkerNetwork.addEdge(constants::validLink14, constants::acquaintance);
      const auto insertionWithInvalidId2 = stalkerNetwork.addEdge(constants::validLink41, constants::acquaintance);
      THEN("the operations fail due to the non existing nodes") {
        REQUIRE_FALSE(insertionWithInvalidId);
        REQUIRE_FALSE(insertionWithInvalidId2);
      }
    }

    WHEN("a second edge with a different id is added") {
      const auto insertionWithDifferentId = stalkerNetwork.addEdge(constants::validLink13, constants::brotherhood);
      THEN("the operation is successful") {
        REQUIRE(insertionWithDifferentId);
      }
    }

    WHEN("a second edge with a the inverted direction is added") {
      const auto insertionWithInverseDirection = stalkerNetwork.addEdge(constants::validLink21, constants::brotherhood);
      THEN("the operation is successful") {
        REQUIRE(insertionWithInverseDirection);
      }
    }
  }
}

SCENARIO("Access to edge by Id", "[DirectedGraph]") {

  GIVEN("A network of stalkers") {
    DirectedGraph<uint8_t, std::string, uint8_t> stalkerNetwork;
    stalkerNetwork.addNode(constants::person1Id, constants::person1Name);
    stalkerNetwork.addNode(constants::person2Id, constants::person2Name);
    stalkerNetwork.addNode(constants::person3Id, constants::person3Name);

    stalkerNetwork.addEdge(constants::validLink12, constants::brotherhood);

    WHEN("the info for that connection is accessed") {
      const auto edgeInfo = stalkerNetwork.getEdge(constants::validLink12);
      THEN("that info matches the one on the insertion") {
        REQUIRE(edgeInfo == constants::brotherhood);
      }
    }

    WHEN("the info for an non existing connection is accessed") {
      THEN("exception is thrown") {
        // Here be dragons
        CHECK_THROWS(stalkerNetwork.getEdge(constants::validLink13));
      }
    }
  }
}

SCENARIO("Remove edge", "[DirectedGraph]") {

  GIVEN("A network of stalkers") {
    DirectedGraph<uint8_t, std::string, uint8_t> stalkerNetwork;
    stalkerNetwork.addNode(constants::person1Id, constants::person1Name);
    stalkerNetwork.addNode(constants::person2Id, constants::person2Name);
    stalkerNetwork.addNode(constants::person3Id, constants::person3Name);

    stalkerNetwork.addEdge(constants::validLink12, constants::brotherhood);
    stalkerNetwork.addEdge(constants::validLink13, constants::acquaintance);
    stalkerNetwork.addEdge(constants::validLink31, constants::friendship);
    stalkerNetwork.addEdge(constants::validLink23, constants::brotherhood);

    WHEN("one connection is removed") {
      stalkerNetwork.removeEdge(constants::validLink12);
      THEN("that connection is no longer be accessible, but the remaining connection are not affected") {
        CHECK_THROWS(stalkerNetwork.getEdge(constants::validLink12));

        REQUIRE(stalkerNetwork.getEdge(constants::validLink13) == constants::acquaintance);
        REQUIRE(stalkerNetwork.getEdge(constants::validLink31) == constants::friendship);
        REQUIRE(stalkerNetwork.getEdge(constants::validLink23) == constants::brotherhood);
      }
    }
  }
}

SCENARIO("Get neighbours for node", "[DirectedGraph]") {

  GIVEN("A network of stalkers") {
    DirectedGraph<uint8_t, std::string, uint8_t> stalkerNetwork;
    stalkerNetwork.addNode(constants::person1Id, constants::person1Name);
    stalkerNetwork.addNode(constants::person2Id, constants::person2Name);
    stalkerNetwork.addNode(constants::person3Id, constants::person3Name);

    stalkerNetwork.addEdge(constants::validLink12, constants::brotherhood);
    stalkerNetwork.addEdge(constants::validLink13, constants::acquaintance);
    stalkerNetwork.addEdge(constants::validLink23, constants::brotherhood);

    WHEN("getting the list of people that person1 stalks") {
      const auto stalkees1 = stalkerNetwork.neighbours(constants::person1Id);
      const auto stalkees2 = stalkerNetwork.neighbours(constants::person2Id);
      const auto stalkees3 = stalkerNetwork.neighbours(constants::person3Id);
      THEN("the results come as expected") {
        REQUIRE(stalkees1.size() == 2);
        REQUIRE(stalkees1.contains(constants::person2Id));
        REQUIRE(stalkees1.contains(constants::person3Id));

        REQUIRE(stalkees2.size() == 1);
        REQUIRE(stalkees2.contains(constants::person3Id));

        REQUIRE(stalkees3.empty());
      }
    }
  }
}

SCENARIO("Remove node with connections", "[DirectedGraph]") {

  GIVEN("A network of stalkers") {
    DirectedGraph<uint8_t, std::string, uint8_t> stalkerNetwork;
    stalkerNetwork.addNode(constants::person1Id, constants::person1Name);
    stalkerNetwork.addNode(constants::person2Id, constants::person2Name);
    stalkerNetwork.addNode(constants::person3Id, constants::person3Name);

    stalkerNetwork.addEdge(constants::validLink12, constants::brotherhood);
    stalkerNetwork.addEdge(constants::validLink13, constants::acquaintance);
    stalkerNetwork.addEdge(constants::validLink23, constants::brotherhood);

    WHEN("removing a person from the network") {
      stalkerNetwork.removeNode(constants::person1Id);
      THEN("the connections made to that person disappear") {

        const auto stalkees2 = stalkerNetwork.neighbours(constants::person2Id);
        REQUIRE(stalkees2.size() == 1);
        REQUIRE(stalkees2.contains(constants::person3Id));

        const auto stalkees3 = stalkerNetwork.neighbours(constants::person3Id);
        REQUIRE(stalkees3.empty());
      }
    }

    WHEN("removing another person from the network") {
      stalkerNetwork.removeNode(constants::person2Id);
      THEN("the connections made to that person disappear") {

        const auto stalkees1 = stalkerNetwork.neighbours(constants::person1Id);
        REQUIRE(stalkees1.size() == 1);
        REQUIRE(stalkees1.contains(constants::person3Id));

        const auto stalkees3 = stalkerNetwork.neighbours(constants::person3Id);
        REQUIRE(stalkees3.empty());
      }
    }
  }
}
