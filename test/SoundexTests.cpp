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

TEST_F(SoundexTests, removeAllUnnecesaryLetters)
{
    ASSERT_EQ("Hnmn", s.removeUnnecesaryLetters("Honeyman"));
}

TEST_F(SoundexTests, replaceLettersWithNumbers)
{
    ASSERT_EQ("H555", s.replaceLettersWithNumbers("Hnmn"));
    ASSERT_EQ("R111", s.replaceLettersWithNumbers("Rbfp"));
    ASSERT_EQ("R163", s.replaceLettersWithNumbers("Rbrt"));
}
