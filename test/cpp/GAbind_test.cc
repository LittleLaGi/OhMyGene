#include "GAbind.hpp"

#include <gtest/gtest.h>


class GAbindTest : public ::testing::Test {
protected:

  GAbindTest() {
    // Do set-up work for each test here.
  }

  ~GAbindTest() override {
    // Do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, define the following methods:

  void SetUp() override {
    // Code here will be called immediately after the constructor (right before each test).
  }

  void TearDown() override {
    // Code here will be called immediately after each test (right before the destructor).
  }

};


TEST_F(GAbindTest, DummyTest) {
  ASSERT_NE(1, 0);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}