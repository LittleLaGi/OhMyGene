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

  GA ga1 = GA(
            5,  // gene_count
            {{0, 100}, {0, 100}, {0, 100}, {0, 100}, {0, 100}}, // gene_bound
            100,  // generation_number
            10, // population_size
            0.5,  // mating_parent_ratio
            0.01, // mutation_probability
            {0.2, 0.2, 0.2, 0.2, 0.2},  // weights
            "random", // parent_selection_method
            "single_point", // cross_over_methods
            "random"  // mutation_methods
            );

  GA ga2 = GA(
            5,  // gene_count
            {{0, 100}, {0, 100}, {0, 100}, {0, 100}, {0, 100}}, // gene_bound
            100,  // generation_number
            15, // population_size
            0.5,  // mating_parent_ratio
            0.01, // mutation_probability
            {0.2, 0.2, 0.2, 0.2, 0.2},  // weights
            "random", // parent_selection_method
            "single_point", // cross_over_methods
            "random"  // mutation_methods
            );
};


TEST_F(GAbindTest, createInitialPopulationTest) {
  ga1.createInitialPopulation();
  auto parents = ga1.getParents();
  for (auto& t : parents){
    auto gene = std::get<0>(t);
    for (size_t i = 0; i < gene.size(); ++i) {
      const size_t lower = std::get<0>(ga1.getGeneBound()[i]);
      const size_t upper = std::get<1>(ga1.getGeneBound()[i]);
      EXPECT_GE(gene[i], lower);
      EXPECT_LE(gene[i], upper);
    }
  }
}

TEST_F(GAbindTest, MatingParentNumTest) {
  EXPECT_EQ(ga1.getMatingParentNum(), 5);
  EXPECT_EQ(ga2.getMatingParentNum(), 7);
}

TEST_F(GAbindTest, randomSelectionTest) {
  for (auto i : ga1.selectParents()){
    EXPECT_GE(i, 0);
    EXPECT_LT(i, ga1.getPopulationSize());
  }
  
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}