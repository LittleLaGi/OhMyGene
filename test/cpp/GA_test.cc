#include "GA.hpp"

#include <gtest/gtest.h>


class GAbindTest : public ::testing::Test {
protected:

  GAbindTest() {
    // Do set-up work for each test here.
    ga1.createInitialPopulation();
    ga1.evaluateFitnessValue();
    ga1.selectParents();
    ga1.crossover();
    ga1.mutation();
    
    ga2.createInitialPopulation();
    ga2.evaluateFitnessValue();
    ga2.selectParents();
    ga2.crossover();
    ga2.mutation();
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
  
  auto parents = ga1.getParents();
  for (auto& t : parents){
    auto gene = std::get<0>(t);
    for (size_t i = 0; i < gene.size(); ++i) {
      const size_t lower = std::get<0>(ga1.getGeneBound()[i]);
      const size_t upper = std::get<1>(ga1.getGeneBound()[i]);
      //std::cout<<"gene[i]: "<<gene[i]<<"; lower: "<<lower<<"\n";
      EXPECT_GE(gene[i], lower);
      EXPECT_LE(gene[i], upper);
    }
  }
}

TEST_F(GAbindTest, MatingParentNumTest) {
  EXPECT_EQ(ga1.getMatingParentNum(), 6);
  EXPECT_EQ(ga2.getMatingParentNum(), 8);
}

TEST_F(GAbindTest, randomSelectionTest) {
  for (size_t count = 0; count < 20; ++count){
    ga1.createInitialPopulation();
    for (auto i : ga1.getSelectedParents()){
      EXPECT_GE(i, 0);
      EXPECT_LT(i, ga1.getPopulationSize());
    }
    ga2.createInitialPopulation();
    for (auto i : ga2.getSelectedParents()){
      EXPECT_GE(i, 0);
      EXPECT_LT(i, ga2.getPopulationSize());
    }
  }
}

TEST_F(GAbindTest, singlePointCrossoverTest){
  auto selected_parents = ga1.getSelectedParents();
  for (size_t i = 0; i < selected_parents.size() - 1; i += 2){
    for (size_t index = 0; index < ga1.getGeneCount(); ++index){
      auto gene1 = std::get<0>(ga1.getParents()[selected_parents[i]]);
      auto gene2 = std::get<0>(ga1.getParents()[selected_parents[i + 1]]);
      auto child_gene = std::get<0>(ga1.singlePointCrossover(index, selected_parents[i], selected_parents[i + 1]));
      for (size_t j = 0; j < index; ++j)
        EXPECT_EQ(child_gene[j], gene1[j]);
      for (size_t j = index; j < ga1.getGeneCount(); ++j)
        EXPECT_EQ(child_gene[j], gene2[j]);
    }
  }
}

TEST_F(GAbindTest, crossoverTest){
  // test selected parents
  for (size_t i = 0; i < ga1.getSelectedParents().size(); ++i){
    auto gene_p = std::get<0>(ga1.getParents()[ga1.getSelectedParents()[i]]);
    auto fitness_p = std::get<1>(ga1.getParents()[ga1.getSelectedParents()[i]]);
    auto gene_c = std::get<0>(ga1.getChildren()[i]);
    auto fitness_c = std::get<1>(ga1.getChildren()[i]);
    for (size_t j = 0; j < gene_p.size(); ++j)
      EXPECT_EQ(gene_p[j], gene_c[j]);
    EXPECT_EQ(fitness_p, fitness_c);
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}