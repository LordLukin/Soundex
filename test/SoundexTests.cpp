#include <gtest/gtest.h>
#include "Soundex.hpp"

struct SoundexTests : public ::testing::Test
{
    Soundex s;
};

TEST_F(SoundexTests, assertThatSoundexForRoIsR)
{
    ASSERT_EQ(s.soundex("Ro"),"R000");
}

TEST_F(SoundexTests, assertThatSoundexForFirstLetterIsThatLetter)
{
    ASSERT_EQ(s.soundex("J"),"J000");
    ASSERT_EQ(s.soundex("R"),"R000");
}

TEST_F(SoundexTests, verifyNonConsolantsIsRemove)
{
    ASSERT_EQ(s.soundex("Raa"),"R000");
    ASSERT_EQ(s.soundex("Goo"),"G000");

}
TEST_F(SoundexTests, dropExcluded)
{
    ASSERT_EQ(s.soundex("Aaeiouyhw"),"A000");
}


TEST_F(SoundexTests, replaceConsonants)
{
    ASSERT_EQ(s.soundex("Aum"),"A500");
    ASSERT_EQ(s.soundex("Rod"),"R300");
}

TEST_F(SoundexTests, replaceConsonants_b_f_p_v)
{
    ASSERT_EQ(s.soundex("Aubfpv"),"A100");
}

TEST_F(SoundexTests, replaceConsonants_c_g_j_k_q_s_x_z)
{
    ASSERT_EQ(s.soundex("Cgjkqsxz"),"C000");
}

TEST_F(SoundexTests, replaceConsonants_d_t_l_m_n_r)
{
    ASSERT_EQ(s.soundex("Dtlmnr"), "D456");
}

TEST_F(SoundexTests, Robert_Rupert)
{
    ASSERT_EQ(s.soundex("Robert"), "R163");
    ASSERT_EQ(s.soundex("Rupert"), "R163");
    ASSERT_EQ(s.soundex("Rubin"), "R150");
    ASSERT_EQ(s.soundex("Ashcraft"), "A261");
    ASSERT_EQ(s.soundex("Ashcroft"), "A261");
    ASSERT_EQ(s.soundex("Tymczak"), "T522");
    ASSERT_EQ(s.soundex("Pfister"), "P236");

}
TEST_F(SoundexTests, DISABLED_honeyman)
{
    ASSERT_EQ(s.soundex("Honeyman"), "H555");
}
