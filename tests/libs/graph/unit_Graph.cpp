//
// Created by nolasco on 14/05/20.
//

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "constants.h"
#include "interface/graph/UndirectedGraph.h"

SCENARIO("Addition of nodes to graph independent of directionality", "[BaseGraph]") {

  GIVEN("A network with one person") {
    UndirectedGraph<uint8_t, std::string, uint8_t> friendNetwork;
    REQUIRE(friendNetwork.addNode(constants::person1Id, constants::person1Name));

    WHEN("a second node with the same id is added") {
      const auto insertionWithSameId = friendNetwork.addNode(constants::person1Id, constants::person2Name);
      THEN("the operation fails due to repeated id") {
        REQUIRE_FALSE(insertionWithSameId);
      }
    }

    WHEN("a second node with a different id is added") {
      const auto insertionWithDifferentId = friendNetwork.addNode(constants::person2Id, constants::person2Name);
      THEN("the operation is successful") {
        REQUIRE(insertionWithDifferentId);
      }
    }
  }
}

SCENARIO("Access to node by Id", "[BaseGraph]") {

  GIVEN("A network with one person") {
    UndirectedGraph<uint8_t, std::string, uint8_t> friendNetwork;
    friendNetwork.addNode(constants::person1Id, constants::person1Name);

    WHEN("the info for that person is accessed") {
      const auto person1Name = friendNetwork.getNode(constants::person1Id);
      THEN("that info matches the one on the insertion") {
        REQUIRE(person1Name == constants::person1Name);
      }
    }

    WHEN("the info for an non existing person is accessed") {
      THEN("exception is thrown") {
        // Here be dragons
        CHECK_THROWS(friendNetwork.getNode(constants::person2Id));
      }
    }
  }
}

SCENARIO("Remove node", "[BaseGraph]") {

  GIVEN("A network of friends") {
    UndirectedGraph<uint8_t, std::string, uint8_t> friendNetwork;
    friendNetwork.addNode(constants::person1Id, constants::person1Name);
    friendNetwork.addNode(constants::person2Id, constants::person2Name);

    WHEN("one person is removed") {
      friendNetwork.removeNode(constants::person1Id);
      THEN("that person is no longer be accessible, but the remaining people are not affected") {
        CHECK_THROWS(friendNetwork.getNode(constants::person1Id));

        REQUIRE(friendNetwork.getNode(constants::person2Id) == constants::person2Name);
      }
    }
  }
}
