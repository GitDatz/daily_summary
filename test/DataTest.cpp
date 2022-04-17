#include <gtest/gtest.h>

TEST(DataTests, DummyDataTest)
{
    const auto expected = 1;
    const auto actual = 1;
    ASSERT_EQ(expected, actual);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
