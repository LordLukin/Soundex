#include <gtest/gtest.h>
#include "Soundex.hpp"

struct SoundexTests : public ::testing::Test
{
    Soundex s;
};

TEST_F(SoundexTests, assertThatSoundexForRoIsR)
{
    ASSERT_EQ(s.soundex("Ro"),"R");
}

TEST_F(SoundexTests, assertThatSoundexForFirstLetterIsThatLetter)
{
    ASSERT_EQ(s.soundex("J"),"J");
    ASSERT_EQ(s.soundex("R"),"R");
}

TEST_F(SoundexTests, verifyNonConsolantsIsRemove)
{
    ASSERT_EQ(s.soundex("Raa"),"R");
    ASSERT_EQ(s.soundex("Goo"),"G");

}
TEST_F(SoundexTests, dropExcluded)
{
    ASSERT_EQ(s.soundex("Aaeiouyhw"),"A");
}

TEST_F(SoundexTests, replaceConsonants)
{
    ASSERT_EQ(s.soundex("Aum"),"A5");
    ASSERT_EQ(s.soundex("Rod"),"R3");
}
