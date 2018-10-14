#include <gtest/gtest.h>
#include "Soundex.hpp"

struct SoundexTests : public ::testing::Test
{

    Soundex soundex;
    std::string name = "Robrt";
};

TEST_F(SoundexTests, assertThatTrueIsTrue)
{
    ASSERT_TRUE(true);
}

TEST_F(SoundexTests, checksIfRemovesO)
{
    ASSERT_EQ(soundex.removeAEIOUYHW(name), "Rbrt");
}
