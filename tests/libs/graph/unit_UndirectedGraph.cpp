//
// Created by nolasco on 14/05/20.
//

#define CATCH_CONFIG_MAIN
#include <catch2/single_include/catch2/catch.hpp>

#include "constants.h"
#include "interface/graph/UndirectedGraph.h"

SCENARIO("Addition of edge directed graph", "[UndirectedGraph]") {

  GIVEN("A network of friends") {
    UndirectedGraph<uint8_t, std::string, uint8_t> friendNetwork;
    friendNetwork.addNode(constants::person1Id, constants::person1Name);
    friendNetwork.addNode(constants::person2Id, constants::person2Name);
    friendNetwork.addNode(constants::person3Id, constants::person3Name);
    REQUIRE(friendNetwork.addEdge(constants::validLink12, constants::brotherhood));

    WHEN("a second edge with the same origin and destination is added") {
      const auto invalidInsertion = friendNetwork.addEdge(constants::invalidLink, constants::acquaintance);
      THEN("the operation fails due to looping connection") {
        REQUIRE_FALSE(invalidInsertion);
      }
    }

    WHEN("a second edge with the same id is added") {
      const auto insertionWithSameId = friendNetwork.addEdge(constants::validLink12, constants::acquaintance);
      THEN("the operation fails due to repeated id") {
        REQUIRE_FALSE(insertionWithSameId);
      }
    }

    WHEN("an edge is added with an invalid origin or destination") {
      const auto insertionWithInvalidId = friendNetwork.addEdge(constants::validLink14, constants::acquaintance);
      const auto insertionWithInvalidId2 = friendNetwork.addEdge(constants::validLink41, constants::acquaintance);
      THEN("the operations fail due to the non existing nodes") {
        REQUIRE_FALSE(insertionWithInvalidId);
        REQUIRE_FALSE(insertionWithInvalidId2);
      }
    }

    WHEN("a second edge with a different id is added") {
      const auto insertionWithDifferentId = friendNetwork.addEdge(constants::validLink13, constants::brotherhood);
      THEN("the operation is successful") {
        REQUIRE(insertionWithDifferentId);
      }
    }

    WHEN("a second edge with a the inverted direction is added") {
      const auto insertionWithInverseDirection = friendNetwork.addEdge(constants::validLink21, constants::brotherhood);
      THEN("the operation is fails since it repeats the connection") {
        REQUIRE_FALSE(insertionWithInverseDirection);
      }
    }
  }
}

SCENARIO("Access to edge by Id", "[UndirectedGraph]") {

  GIVEN("A network of friends") {
    UndirectedGraph<uint8_t, std::string, uint8_t> friendNetwork;
    friendNetwork.addNode(constants::person1Id, constants::person1Name);
    friendNetwork.addNode(constants::person2Id, constants::person2Name);
    friendNetwork.addNode(constants::person3Id, constants::person3Name);

    friendNetwork.addEdge(constants::validLink12, constants::brotherhood);

    WHEN("the info for that connection is accessed") {
      const auto edgeInfo = friendNetwork.getEdge(constants::validLink12);
      THEN("that info matches the one on the insertion") {
        REQUIRE(edgeInfo == constants::brotherhood);
      }
    }

    WHEN("the info for an non existing connection is accessed") {
      THEN("exception is thrown") {
        // Here be dragons
        CHECK_THROWS(friendNetwork.getEdge(constants::validLink13));
      }
    }
  }
}

SCENARIO("Remove edge", "[UndirectedGraph]") {

  GIVEN("A network of friends") {
    UndirectedGraph<uint8_t, std::string, uint8_t> friendNetwork;
    friendNetwork.addNode(constants::person1Id, constants::person1Name);
    friendNetwork.addNode(constants::person2Id, constants::person2Name);
    friendNetwork.addNode(constants::person3Id, constants::person3Name);

    friendNetwork.addEdge(constants::validLink12, constants::brotherhood);
    friendNetwork.addEdge(constants::validLink13, constants::acquaintance);
    friendNetwork.addEdge(constants::validLink23, constants::brotherhood);

    WHEN("one connection is removed") {
      friendNetwork.removeEdge(constants::validLink12);
      THEN("that connection is no longer be accessible, but the remaining connection are not affected") {
        CHECK_THROWS(friendNetwork.getEdge(constants::validLink12));
        CHECK_THROWS(friendNetwork.getEdge(constants::validLink21));

        REQUIRE(friendNetwork.getEdge(constants::validLink13) == constants::acquaintance);
        REQUIRE(friendNetwork.getEdge(constants::validLink31) == constants::acquaintance);

        REQUIRE(friendNetwork.getEdge(constants::validLink23) == constants::brotherhood);
        REQUIRE(friendNetwork.getEdge(constants::validLink32) == constants::brotherhood);
      }
    }
  }
}

SCENARIO("Get neighbours for node", "[UndirectedGraph]") {

  GIVEN("A network of friends") {
    UndirectedGraph<uint8_t, std::string, uint8_t> friendNetwork;
    friendNetwork.addNode(constants::person1Id, constants::person1Name);
    friendNetwork.addNode(constants::person2Id, constants::person2Name);
    friendNetwork.addNode(constants::person3Id, constants::person3Name);

    friendNetwork.addEdge(constants::validLink12, constants::brotherhood);
    friendNetwork.addEdge(constants::validLink13, constants::acquaintance);
    friendNetwork.addEdge(constants::validLink23, constants::brotherhood);

    WHEN("getting the list of people that person1 stalks") {
      const auto stalkees1 = friendNetwork.neighbours(constants::person1Id);
      const auto stalkees2 = friendNetwork.neighbours(constants::person2Id);
      const auto stalkees3 = friendNetwork.neighbours(constants::person3Id);
      THEN("the results come as expected") {
        REQUIRE(stalkees1.size() == 2);
        REQUIRE(stalkees1.contains(constants::person2Id));
        REQUIRE(stalkees1.contains(constants::person3Id));

        REQUIRE(stalkees2.size() == 2);
        REQUIRE(stalkees2.contains(constants::person1Id));
        REQUIRE(stalkees2.contains(constants::person3Id));

        REQUIRE(stalkees3.size() == 2);
        REQUIRE(stalkees3.contains(constants::person1Id));
        REQUIRE(stalkees3.contains(constants::person2Id));
      }
    }
  }
}

SCENARIO("Remove node with connections", "[UndirectedGraph]") {

  GIVEN("A network of friends") {
    UndirectedGraph<uint8_t, std::string, uint8_t> friendNetwork;
    friendNetwork.addNode(constants::person1Id, constants::person1Name);
    friendNetwork.addNode(constants::person2Id, constants::person2Name);
    friendNetwork.addNode(constants::person3Id, constants::person3Name);

    friendNetwork.addEdge(constants::validLink12, constants::brotherhood);
    friendNetwork.addEdge(constants::validLink13, constants::acquaintance);
    friendNetwork.addEdge(constants::validLink23, constants::brotherhood);

    WHEN("removing a person from the network") {
      friendNetwork.removeNode(constants::person1Id);
      THEN("the connections made to that person disappear") {

        const auto stalkees2 = friendNetwork.neighbours(constants::person2Id);
        REQUIRE(stalkees2.size() == 1);
        REQUIRE(stalkees2.contains(constants::person3Id));

        const auto stalkees3 = friendNetwork.neighbours(constants::person3Id);
        REQUIRE(stalkees3.size() == 1);
        REQUIRE(stalkees3.contains(constants::person2Id));
      }
    }

    WHEN("removing another person from the network") {
      friendNetwork.removeNode(constants::person2Id);
      THEN("the connections made to that person disappear") {

        const auto stalkees1 = friendNetwork.neighbours(constants::person1Id);
        REQUIRE(stalkees1.size() == 1);
        REQUIRE(stalkees1.contains(constants::person3Id));

        const auto stalkees3 = friendNetwork.neighbours(constants::person3Id);
        REQUIRE(stalkees3.size() == 1);
        REQUIRE(stalkees3.contains(constants::person1Id));
      }
    }
  }
}
