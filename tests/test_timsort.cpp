#include <gtest/gtest.h>
#include "timsort.h"
#include "timsort.tpp"

TEST(TimSortTest, BasicAssertions) {
    std::vector<int> data = {5, 3, 8, 4, 2};
    timsort(data);
    ASSERT_EQ(data, (std::vector<int>{2, 3, 4, 5, 8}));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
