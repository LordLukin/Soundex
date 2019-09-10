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
