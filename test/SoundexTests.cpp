#include <gtest/gtest.h>
#include "Soundex.hpp"

struct SoundexTests : public ::testing::Test
{
    Soundex s;
};


TEST_F(SoundexTests, findFirstLetterInWord)
{
    ASSERT_EQ("H", s.returnFirstLetter("Honeyman"));
}

TEST_F(SoundexTests, findFirstLetterInLowerCaseWord)
{
    ASSERT_EQ("R", s.returnFirstLetter("rupert"));
}
