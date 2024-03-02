/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** test_tekspice
*/

#include <gtest/gtest.h>

#include "tekspice.hpp"

TEST(tekspice, gate_nor)
{
    char *args[2] = {strdup("./nano"), strdup("bonus/nts_single/4001_nor.nts")};
    std::istringstream iss("display\n");
    std::streambuf *cinBackup = std::cin.rdbuf(iss.rdbuf());  // Redirect cin

    testing::internal::CaptureStdout();
    EXPECT_EQ(nts::tekspice(2, args), 0);
    std::string output = testing::internal::GetCapturedStdout();
    std::cin.rdbuf(cinBackup);
    EXPECT_EQ(
        output,
        "> tick: 0\n\
input(s):\n\
  in_01: U\n  in_02: U\n  in_05: U\n  in_06: U\n  in_08: U\n  in_09: U\n  in_12: U\n  in_13: U\noutput(s):\n\
  out_03: U\n  out_04: U\n  out_10: U\n  out_11: U\n> ");
}

TEST(tekspice, gate_nand)
{
    char *args[2] = {
        strdup("./nano"), strdup("bonus/nts_single/4011_nand.nts")};
    std::istringstream iss("display\n");
    std::streambuf *cinBackup = std::cin.rdbuf(iss.rdbuf());  // Redirect cin

    testing::internal::CaptureStdout();
    EXPECT_EQ(nts::tekspice(2, args), 0);
    std::string output = testing::internal::GetCapturedStdout();
    std::cin.rdbuf(cinBackup);
    EXPECT_EQ(
        output,
        "> tick: 0\n\
input(s):\n\
  in_01: U\n  in_02: U\n  in_05: U\n  in_06: U\n  in_08: U\n  in_09: U\n  in_12: U\n  in_13: U\noutput(s):\n\
  out_03: U\n  out_04: U\n  out_10: U\n  out_11: U\n> ");
}

TEST(tekspice, gate_xor)
{
    char *args[2] = {strdup("./nano"), strdup("bonus/nts_single/4030_xor.nts")};
    std::istringstream iss("display\n");
    std::streambuf *cinBackup = std::cin.rdbuf(iss.rdbuf());  // Redirect cin

    testing::internal::CaptureStdout();
    EXPECT_EQ(nts::tekspice(2, args), 0);
    std::string output = testing::internal::GetCapturedStdout();
    std::cin.rdbuf(cinBackup);
    EXPECT_EQ(
        output,
        "> tick: 0\n\
input(s):\n\
  in_01: U\n  in_02: U\n  in_05: U\n  in_06: U\n  in_08: U\n  in_09: U\n  in_12: U\n  in_13: U\noutput(s):\n\
  out_03: U\n  out_04: U\n  out_10: U\n  out_11: U\n> ");
}

TEST(tekspice, gate_or)
{
    char *args[2] = {strdup("./nano"), strdup("bonus/nts_single/4071_or.nts")};
    std::istringstream iss("display\n");
    std::streambuf *cinBackup = std::cin.rdbuf(iss.rdbuf());  // Redirect cin

    testing::internal::CaptureStdout();
    EXPECT_EQ(nts::tekspice(2, args), 0);
    std::string output = testing::internal::GetCapturedStdout();
    std::cin.rdbuf(cinBackup);
    EXPECT_EQ(
        output,
        "> tick: 0\n\
input(s):\n\
  in_01: U\n  in_02: U\n  in_05: U\n  in_06: U\n  in_08: U\n  in_09: U\n  in_12: U\n  in_13: U\noutput(s):\n\
  out_03: U\n  out_04: U\n  out_10: U\n  out_11: U\n> ");
}

TEST(tekspice, gate_and)
{
    char *args[2] = {strdup("./nano"), strdup("bonus/nts_single/4081_and.nts")};
    std::istringstream iss("display\n");
    std::streambuf *cinBackup = std::cin.rdbuf(iss.rdbuf());  // Redirect cin

    testing::internal::CaptureStdout();
    EXPECT_EQ(nts::tekspice(2, args), 0);
    std::string output = testing::internal::GetCapturedStdout();
    std::cin.rdbuf(cinBackup);
    EXPECT_EQ(
        output,
        "> tick: 0\n\
input(s):\n\
  in_01: U\n  in_02: U\n  in_05: U\n  in_06: U\n  in_08: U\n  in_09: U\n  in_12: U\n  in_13: U\noutput(s):\n\
  out_03: U\n  out_04: U\n  out_10: U\n  out_11: U\n> ");
}

TEST(tekspice, gate_not)
{
    char *args[2] = {strdup("./nano"), strdup("bonus/nts_single/4069_not.nts")};
    std::istringstream iss("display\n");
    std::streambuf *cinBackup = std::cin.rdbuf(iss.rdbuf());  // Redirect cin

    testing::internal::CaptureStdout();
    EXPECT_EQ(nts::tekspice(2, args), 0);
    std::string output = testing::internal::GetCapturedStdout();
    std::cin.rdbuf(cinBackup);
    EXPECT_EQ(
        output,
        "> tick: 0\n\
input(s):\n\
  in_01: U\n  in_03: U\n  in_05: U\n  in_09: U\n  in_11: U\n  in_13: U\noutput(s):\n\
  out_02: U\n  out_04: U\n  out_06: U\n  out_08: U\n  out_10: U\n  out_12: U\n> ");
}
