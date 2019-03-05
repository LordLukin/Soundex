#include <gtest/gtest.h>
#include "Soundex.hpp"

struct SoundexTests : public ::testing::Test
{
    Soundex s;
};

TEST_F(SoundexTests, convertSoundex)
{
    ASSERT_EQ("R163", s.convert("Robert"));
    ASSERT_EQ("R163", s.convert("Rupert"));
    ASSERT_EQ("P436", s.convert("Plotter"));
    ASSERT_EQ("R000", s.convert("R"));
    ASSERT_EQ("R163", s.convert("Robertrobertrobert"));
    ASSERT_EQ("R150", s.convert("Rubin"));
    ASSERT_EQ("H500", s.convert("Honeyman"));
    ASSERT_EQ("A261", s.convert("Ashcraft"));
    ASSERT_EQ("A261", s.convert("Ashcroft"));
    ASSERT_EQ("T520", s.convert("Tymczak"));
    ASSERT_EQ("P123", s.convert("Pfister"));
}
