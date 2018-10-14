#include <gtest/gtest.h>
#include "Soundex.hpp"

struct SoundexTests : public ::testing::Test
{

    Soundex soundex;
    std::string name = "Robrt";
    std::string name2 = "R";
    std::string name3 = "J";
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

TEST_F(SoundexTests, GivenOneLetterReplaceToDigitsShouldReturnJ000)
{
    ASSERT_EQ(soundex.replaceToDigits(name3),"J000");
}
