#include <gtest/gtest.h>
#include "Soundex.hpp"

struct SoundexTests : public ::testing::Test
{

};

TEST_F(SoundexTests, assertThatTrueIsTrue)
{
    ASSERT_TRUE(true);
}

TEST_F(SoundexTests, findFirstLetterInWord)
{
    Soundex s;
    ASSERT_EQ("H", s.returnFirstLetter("Honeyman"));
}
