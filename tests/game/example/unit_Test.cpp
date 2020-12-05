//
// Created by nolasco on 28/11/20.
//

#include <main_test.h>
#include <trompeloeil/include/catch2/trompeloeil.hpp>

class Base {
public:
  Base() = default;
  explicit Base(int init) : n(init){};
  virtual std::string secret(int) = 0;

private:
  int n;
};

class MockImpl : public Base {
public:
  MAKE_MOCK1(secret, std::string(int), override);
};

class MockImpl2 : public trompeloeil::mock_interface<Base> {
public:
  IMPLEMENT_MOCK1(secret);
};

class RealImpl : public Base {
public:
  RealImpl() = delete;
  explicit RealImpl(int n) : Base(n){};
  std::string secret(int n) {
    switch (n) {
      case 0:
        return "zero";
      case 1:
        return "one";
      default:
        throw std::invalid_argument("Fail");
    }
  };
};

class Wrapper {
public:
  Wrapper(const std::shared_ptr<Base> &base) : base(std::move(base)) {
  }
  bool checkMe() {
    return base->secret(1) == "one";
  }

private:
  std::shared_ptr<Base> base;
};

SCENARIO("Dependency injection", "[Test]") {

  GIVEN("e objects") {
    std::vector<std::string> dict{"zero", "one"};

    auto mock = std::make_shared<MockImpl>();
    ALLOW_CALL(*mock.get(), secret(trompeloeil::_)).RETURN(dict[_1]);
    REQUIRE(mock->secret(1) == "one");

    auto mock2 = std::make_shared<MockImpl2>();
    ALLOW_CALL(*mock2.get(), secret(trompeloeil::_)).RETURN(dict[_1]);
    REQUIRE(mock2->secret(1) == "one");

    auto real = std::make_shared<RealImpl>(2);
    REQUIRE(real->secret(1) == "one");

    WHEN("A wrapper class is called") {
      auto wrapperR = Wrapper(real);
      auto wrapperM = Wrapper(mock);
      auto wrapperM2 = Wrapper(mock2);
      THEN("The call is successful") {
        REQUIRE(wrapperR.checkMe());
        REQUIRE(wrapperM.checkMe());
        REQUIRE(wrapperM2.checkMe());
      }
    }
  }
}
