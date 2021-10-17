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

  GA ga = GA(5, {{0, 100}, {0, 100}, {0, 100}, {0, 100}, {0, 100}}, 100, 10,
            0.5, 0.01, {0.2, 0.2, 0.2, 0.2, 0.2}, "random", "single_point", "random");

};


TEST_F(GAbindTest, createInitialPopulationTest) {
  auto parents = ga.getParents();
  for (auto& t : parents){
    auto gene = std::get<0>(t);
    for (size_t i = 0; i < gene.size(); ++i) {
      const size_t lower = std::get<0>(ga.getGeneBound()[i]);
      const size_t upper = std::get<1>(ga.getGeneBound()[i]);
      EXPECT_GE(gene[i], lower);
      EXPECT_LE(gene[i], upper);
    }
  }
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}