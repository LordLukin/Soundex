#include <gtest/gtest.h>
#include "Soundex.hpp"

struct SoundexTests : public ::testing::Test
{

    Soundex soundex;
    std::string name = "Robrt";
    std::string name2 = "R";
};

TEST_F(SoundexTests, assertThatTrueIsTrue)
{
    ASSERT_TRUE(true);
}

TEST_F(SoundexTests, checksIfRemovesO)
{
    ASSERT_EQ(soundex.removeAEIOUYHW(name), "Rbrt");
}

TEST_F(SoundexTests, checksIfRemovesAEIOUYHW)
{
    ASSERT_EQ(soundex.removeAEIOUYHW("Robert"),"Rbrt");
}

TEST_F(SoundexTests, GivenRReplaceToDigitsShouldReturnR000)
{
    ASSERT_EQ(soundex.replaceToDigits(name2),"R000");
}
