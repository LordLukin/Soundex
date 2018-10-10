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

TEST_F(SoundexTests, assertThatSoundexForRodIsR3)
{
    ASSERT_EQ(s.soundex("Rod"),"R3");
}


TEST_F(SoundexTests, assertThatSoundexForFirstLetterIsThatLetter)
{
    ASSERT_EQ(s.soundex("J"),"J");
    ASSERT_EQ(s.soundex("R"),"R");
}
