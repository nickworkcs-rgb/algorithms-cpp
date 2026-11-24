#include "algorithms/sorting/bubble_sort.hpp"

#include <gtest/gtest.h>

#include <cstddef>
#include <vector>

struct Counted {
    int value;
    static inline int comparisons{};

    bool operator<(const Counted& other) const {
        comparisons++;
        return value < other.value;
    }
};

TEST(BubbleSort, SortsUnsortedArray) {
    std::vector<int> v{-5, 10, 2, 4, 11, -6};
    std::vector<int> expected{-6, -5, 2, 4, 10, 11};
    algo::bubble_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(BubbleSort, HandlesEmptyArray) {
    std::vector<int> v;
    algo::bubble_sort(v);
    EXPECT_TRUE(v.empty());
}

TEST(BubbleSort, HandlesSingleElement) {
    std::vector<int> v{2};
    algo::bubble_sort(v);
    std::vector<int> expected{2};
    EXPECT_EQ(v, expected);
}

TEST(BubbleSort, HandlesDuplicates) {
    std::vector<int> v{2, 2, 2, 2, 2};
    algo::bubble_sort(v);
    std::vector<int> expected{2, 2, 2, 2, 2};
    EXPECT_EQ(v, expected);
}

TEST(BubbleSort, SortsReverseSortedArray) {
    std::vector<int> v{6, 4, 2, 1, -6};
    algo::bubble_sort(v);
    std::vector<int> expected{-6, 1, 2, 4, 6};
    EXPECT_EQ(v, expected);
}

TEST(BubbleSort, ExitsEarlyWhenArrayIsSorted) {
    std::vector<Counted> v;
    constexpr std::size_t size{1000};
    v.reserve(size);
    for (std::size_t i = 0; i < size; i++) {
        v.emplace_back(static_cast<int>(i));
    }

    Counted::comparisons = 0;
    algo::bubble_sort(v);
    EXPECT_EQ(Counted::comparisons, static_cast<int>(size) - 1);
}
