#include "gtest/gtest.h"
#include "radix_sort.h"

TEST(RadixSortTest, BasicAssertions) {
    std::vector<int> arr = {5, 3, 8, 6, 2, 7, 4, 1};
    radix_sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8}));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
