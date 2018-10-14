#include <gtest/gtest.h>
#include "Soundex.hpp"

struct SoundexTests : public ::testing::Test
{
        Soundex s;
};

TEST_F(SoundexTests, check_if_big_letter_returns_000)
{
    ASSERT_EQ("R000", s.decode("R"));
    ASSERT_EQ("R000", s.decode("r"));
}


TEST_F(SoundexTests, check_if_given_2_letters_except_proper_numbers)
{
    ASSERT_EQ("R100", s.decode("rb"));
    ASSERT_EQ("R200", s.decode("rc"));
    ASSERT_EQ("R300", s.decode("rd"));
    ASSERT_EQ("R400", s.decode("rl"));
    ASSERT_EQ("R500", s.decode("rm"));
    ASSERT_EQ("R600", s.decode("rr"));
    ASSERT_EQ("R100", s.decode("rv"));
    ASSERT_EQ("R200", s.decode("rg"));
    ASSERT_EQ("B200", s.decode("Bc"));
}

TEST_F(SoundexTests, check_if_given_bcc_letter_except_B220)
{
    std::string out = s.decode("Bcc");
    ASSERT_EQ("B220", out);
}


