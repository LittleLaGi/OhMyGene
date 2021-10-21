#include "GA.hpp"

#include <numeric>
#include <cmath>
#include <ostream>
#include <string>
#include <algorithm>

#include <gtest/gtest.h>

double objFunc1(std::vector<double>){
  return 1.0;
}

double objFunc2(std::vector<double>){
  return 1.0;
}

class GAbindTest : public ::testing::Test {
protected:

  GAbindTest() {
    // Do set-up work for each test here.
    ga1.createInitialPopulation();
    
    ga1.clearObjtiveFunctions();
    ga1.addObjectiveFunctionsDebug(&objFunc1);
    ga1.addObjectiveFunctionsDebug(&objFunc2);

    ga1.evaluateFitnessValue();
    ga1.updateElites();
    ga1.updateSelectedOrder();
    ga1.crossover();
    ga1.mutation();
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
            {{-10, 10}, {-10, 10}, {-10, 10}, {-10, 10}, {-10, 10}}, // gene_bound
            100,  // generation_number
            10, // population_size
            0.01, // mutation_probability
            "single_point" // cross_over_methods
            );
};

TEST_F(GAbindTest, generateRandomWeightsTest){
  auto weights = ga1.getWeights();
  ASSERT_EQ(weights.size(), ga1.getPopulationSize());
  for (auto &w : weights){
    ASSERT_EQ(w.size(), ga1.getObjectiveFunctions().size());
    EXPECT_EQ(round(std::accumulate(w.begin(), w.end(), 0.0)), 1);
    for (auto e : w){
      EXPECT_GE(e, 0);
      EXPECT_LE(e, 1);
    }
  }
}

TEST_F(GAbindTest, createInitialPopulationTest) {
  auto parents = ga1.getParents();
  for (auto& gene : parents){
    for (size_t i = 0; i < gene.size(); ++i) {
      const double lower = std::get<0>(ga1.getGeneBound()[i]);
      const double upper = std::get<1>(ga1.getGeneBound()[i]);
      EXPECT_GE(gene[i], lower);
      EXPECT_LE(gene[i], upper);
    }
  }
}

TEST_F(GAbindTest, evaluateFitnessValue){
  auto parents = ga1.getParents();
  auto obj_funcs = ga1.getObjectiveFunctions();
  auto weights = ga1.getWeights();
  for (size_t i = 0; i < parents.size(); ++i){
    double fitness = 0;
    for (size_t j = 0; j < obj_funcs.size(); ++j)
      fitness += weights[i][j] * obj_funcs[j](parents[i]);
    EXPECT_EQ(fitness, ga1.getFitnessValues()[i]);
  }
}

TEST_F(GAbindTest, updateElites){
  for (auto f : ga1.getFitnessValues())
    EXPECT_LE(ga1.getElitesFitnessValue(), f);
}

TEST_F(GAbindTest, updateSelectedOrder){
  auto order = ga1.getSelectedOrder();
  std::sort(order.begin(), order.end());
  for (size_t i = 0; i < ga1.getParents().size(); ++i)
    EXPECT_EQ(order[i], i);
}


// TEST_F(GAbindTest, singlePointCrossoverTest){
//   auto selected_parents = ga1.getSelectedParents();
//   for (size_t i = 0; i < selected_parents.size() - 1; i += 2){
//     for (size_t index = 0; index < ga1.getGeneCount(); ++index){
//       auto gene1 = std::get<0>(ga1.getParents()[selected_parents[i]]);
//       auto gene2 = std::get<0>(ga1.getParents()[selected_parents[i + 1]]);
//       auto child_gene = std::get<0>(ga1.singlePointCrossover(index, selected_parents[i], selected_parents[i + 1]));
//       for (size_t j = 0; j < index; ++j)
//         EXPECT_EQ(child_gene[j], gene1[j]);
//       for (size_t j = index; j < ga1.getGeneCount(); ++j)
//         EXPECT_EQ(child_gene[j], gene2[j]);
//     }
//   }
// }

// TEST_F(GAbindTest, crossoverTest){
//   // test selected parents
//   for (size_t i = 0; i < ga1.getSelectedParents().size(); ++i){
//     auto gene_p = std::get<0>(ga1.getParents()[ga1.getSelectedParents()[i]]);
//     auto fitness_p = std::get<1>(ga1.getParents()[ga1.getSelectedParents()[i]]);
//     auto gene_c = std::get<0>(ga1.getChildren()[i]);
//     auto fitness_c = std::get<1>(ga1.getChildren()[i]);
//     for (size_t j = 0; j < gene_p.size(); ++j)
//       EXPECT_EQ(gene_p[j], gene_c[j]);
//     EXPECT_EQ(fitness_p, fitness_c);
//   }
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}