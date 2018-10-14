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
TEST_F(SoundexTests, GivenTwoLettersReplaceToDigits)
{
    ASSERT_EQ(soundex.replaceToDigits("Rb"),"R100");
    ASSERT_EQ(soundex.replaceToDigits("Rf"),"R100");
    ASSERT_EQ(soundex.replaceToDigits("Hc"),"H200");
    ASSERT_EQ(soundex.replaceToDigits("Hd"),"H300");
    ASSERT_EQ(soundex.replaceToDigits("Hl"),"H400");
    ASSERT_EQ(soundex.replaceToDigits("Hm"),"H500");
    ASSERT_EQ(soundex.replaceToDigits("Hr"),"H600");

}
TEST_F(SoundexTests, GivenThreeLettersReplaceToDigits)
{
    ASSERT_EQ(soundex.replaceToDigits("Rbb"),"R110");
    ASSERT_EQ(soundex.replaceToDigits("Rff"),"R110");
    ASSERT_EQ(soundex.replaceToDigits("Hcc"),"H220");
    ASSERT_EQ(soundex.replaceToDigits("Hdd"),"H330");
    ASSERT_EQ(soundex.replaceToDigits("Hll"),"H440");
    ASSERT_EQ(soundex.replaceToDigits("Hmm"),"H550");
    ASSERT_EQ(soundex.replaceToDigits("Hrr"),"H660");

}
TEST_F(SoundexTests, GivenThreeDifferentLettersReplaceToDigits)
{
    ASSERT_EQ(soundex.replaceToDigits("Hrm"),"H650");
    ASSERT_EQ(soundex.replaceToDigits("Hbb"),"H110");
    ASSERT_EQ(soundex.replaceToDigits("Abc"),"A120");
}
TEST_F(SoundexTests, GivenFourDifferentLettersReplaceToDigits)
{
    ASSERT_EQ(soundex.replaceToDigits("Hrmb"),"H651");
    ASSERT_EQ(soundex.replaceToDigits("Hbbd"),"H113");
    ASSERT_EQ(soundex.replaceToDigits("Abcr"),"A126");
}


