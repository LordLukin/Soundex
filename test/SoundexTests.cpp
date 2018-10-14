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

TEST_F(SoundexTests, check_if_given_bcc_letter_except_B200)
{
    std::string out = s.decode("Bcc");
    ASSERT_EQ("B200", out);
}

TEST_F(SoundexTests, check_if_given_bdln_letter_except_B345)
{
    std::string out = s.decode("Bdln");
    ASSERT_EQ("B345", out);
}

TEST_F(SoundexTests, check_if_given_ba_letter_except_B000)
{
    ASSERT_EQ("B000", s.decode("Ba"));
}

TEST_F(SoundexTests, check_if_given_be_letter_except_B000)
{
    ASSERT_EQ("B000", s.decode("Be"));
}
TEST_F(SoundexTests, check_if_given_bi_letter_except_B000)
{
    ASSERT_EQ("B000", s.decode("Bi"));
}

TEST_F(SoundexTests, check_if_given_bo_letter_except_B000)
{
    ASSERT_EQ("B000", s.decode("Bo"));
}

TEST_F(SoundexTests, check_if_given_bu_letter_except_B000)
{
    ASSERT_EQ("B000", s.decode("Bu"));
}

TEST_F(SoundexTests, check_if_given_bou_letter_except_B000)
{
    ASSERT_EQ("B000", s.decode("Bou"));
}

TEST_F(SoundexTests, check_if_given_boo_letter_except_B000)
{
    ASSERT_EQ("B000", s.decode("Boo"));
}

TEST_F(SoundexTests, check_if_given_Bfmoa_letter_except_B150)
{
    ASSERT_EQ("B150", s.decode("Bfmoa"));
}

TEST_F(SoundexTests, check_if_given_Bbbmoa_letter_except_B150)
{
    ASSERT_EQ("B150", s.decode("Bbbmoa"));
}
