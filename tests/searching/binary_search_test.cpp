#include <gtest/gtest.h>

#include <vector>

#include "algorithms/searching/binary_search.hpp"

TEST(BinarySearch, EmptyArray) {
  std::vector<int> v;
  EXPECT_EQ(algo::binary_search(v, 5), -1);
}

TEST(BinarySearch, SingleElementFound) {
  std::vector<int> v{7};
  EXPECT_EQ(algo::binary_search(v, 7), 0);
}

TEST(BinarySearch, SingleElementNotFound) {
  std::vector<int> v{7};
  EXPECT_EQ(algo::binary_search(v, 8), -1);
}

TEST(BinarySearch, FirstFound) {
  std::vector<int> v{1, 7, 9, 20};
  EXPECT_EQ(algo::binary_search(v, 1), 0);
}

TEST(BinarySearch, LastFound) {
  std::vector<int> v{2, 10, 15, 20, 47, 50};
  EXPECT_EQ(algo::binary_search(v, 50), 5);
}

TEST(BinarySearch, MissingElement) {
  std::vector<int> v{-5, 10, 15, 20, 41, 56, 77};
  EXPECT_EQ(algo::binary_search(v, -10), -1);
  EXPECT_EQ(algo::binary_search(v, 100), -1);
  EXPECT_EQ(algo::binary_search(v, 25), -1);
}

TEST(BinarySearch, FindElementInMiddle) {
  std::vector<int> v1{10, 25, 30, 40};
  std::vector<int> v2{5, 7, 10, 12, 20};
  EXPECT_EQ(algo::binary_search(v1, 25), 1);
  EXPECT_EQ(algo::binary_search(v1, 30), 2);
  EXPECT_EQ(algo::binary_search(v2, 10), 2);
}
