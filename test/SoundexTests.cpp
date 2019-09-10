#include <gtest/gtest.h>
#include "Soundex.hpp"
#include <string>
#include <stdexcept>

struct SoundexTests : public ::testing::Test
{
    Soundex s;
};

TEST_F(SoundexTests, assertSoundexOnEmptyStringThrowError)
{
    std::string input{""};
    ASSERT_THROW(s.doSoundex(input), std::runtime_error);
}

TEST_F(SoundexTests, assertSoundexOnNotEmptyStringDoesNotThrowError)
{
    std::string input{"A"};
    ASSERT_NO_THROW(s.doSoundex(input));
}

TEST_F(SoundexTests, assertSoundexOnStringWithNotCharsThrowError)
{
    std::string input{"A1"};
    ASSERT_THROW(s.doSoundex(input), std::runtime_error);
}

TEST_F(SoundexTests, assertSoundexReturnsFirstLetterAnd000)
{
    std::string input{"A"};
    ASSERT_EQ(s.doSoundex(input), "A000");

    input = "B";
    ASSERT_EQ(s.doSoundex(input), "B000");
}

TEST_F(SoundexTests, assertSoundexOnReturns1OnBFPV)
{
    std::string input{"AB"};
    ASSERT_EQ(s.doSoundex(input), "A100");

    input = "BF";
    ASSERT_EQ(s.doSoundex(input), "B100");

    input = "BP";
    ASSERT_EQ(s.doSoundex(input), "B100");

    input = "BV";
    ASSERT_EQ(s.doSoundex(input), "B100");
}
