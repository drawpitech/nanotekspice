/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** test_tekspice
*/

#include <gtest/gtest.h>

#include "tekspice.hpp"

TEST(tekspice, C4008_adder)
{
    char *args[2] = {
        strdup("./nano"), strdup("bonus/nts_single/4008_adder.nts")};
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
  in_a1: U\n\
  in_a2: U\n\
  in_a3: U\n\
  in_a4: U\n\
  in_b1: U\n\
  in_b2: U\n\
  in_b3: U\n\
  in_b4: U\n\
  in_c: U\n\
output(s):\n\
  out_0: U\n\
  out_1: U\n\
  out_2: U\n\
  out_3: U\n\
  out_c: U\n\
> ");
}

TEST(tekspice, C4013_flipflop)
{
    char *args[2] = {
        strdup("./nano"), strdup("bonus/nts_single/4013_flipflop.nts")};
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
  cl_1_clock: U\n\
  cl_2_clock: U\n\
  in_1_data: U\n\
  in_1_reset: U\n\
  in_1_set: U\n\
  in_2_data: U\n\
  in_2_reset: U\n\
  in_2_set: U\n\
output(s):\n\
  out_1_q: U\n\
  out_1_qb: U\n\
  out_2_q: U\n\
  out_2_qb: U\n\
> ");
}

TEST(tekspice, C4017_jhonson)
{
    char *args[2] = {
        strdup("./nano"), strdup("bonus/nts_single/4017_johnson.nts")};
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
  in_0: U\n\
  in_1: U\n\
  in_r: U\n\
output(s):\n\
  out_0: U\n\
  out_1: U\n\
  out_2: U\n\
  out_3: U\n\
  out_4: U\n\
  out_5: U\n\
  out_6: U\n\
  out_7: U\n\
  out_8: U\n\
  out_9: U\n\
  out_s: U\n\
> ");
}

TEST(tekspice, C4040_counter)
{
    char *args[2] = {
        strdup("./nano"), strdup("bonus/nts_single/4040_counter.nts")};
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
  cl_clock: U\n\
  in_reset: U\n\
output(s):\n\
  out_00: U\n\
  out_01: U\n\
  out_02: U\n\
  out_03: U\n\
  out_04: U\n\
  out_05: U\n\
  out_06: U\n\
  out_07: U\n\
  out_08: U\n\
  out_09: U\n\
  out_10: U\n\
  out_11: U\n\
> ");
}

TEST(tekspice, C4094_shift)
{
    char *args[2] = {
        strdup("./nano"), strdup("bonus/nts_single/4094_shift.nts")};
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
  clock: U\n\
  data: U\n\
output(s):\n\
  out_0: U\n\
  out_1: U\n\
  out_2: U\n\
  out_3: U\n\
  out_4: U\n\
  out_5: U\n\
  out_6: U\n\
  out_7: U\n\
  out_qe: U\n\
  out_qs: U\n\
> ");
}

TEST(tekspice, C4512_selector)
{
    char *args[2] = {
        strdup("./nano"), strdup("bonus/nts_single/4512_selector.nts")};
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
  enable: U\n\
  in_0: U\n\
  in_1: U\n\
  in_2: U\n\
  in_3: U\n\
  in_4: U\n\
  in_5: U\n\
  in_6: U\n\
  in_7: U\n\
  in_a: U\n\
  in_b: U\n\
  in_c: U\n\
  inhibit: U\n\
output(s):\n\
  out_data: U\n\
> ");
}

TEST(tekspice, C4514_decoder)
{
    char *args[2] = {
        strdup("./nano"), strdup("bonus/nts_single/4514_decoder.nts")};
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
  in_0: U\n\
  in_1: U\n\
  in_2: U\n\
  in_3: U\n\
  inhibit: U\n\
  strobe: U\n\
output(s):\n\
  out_00: U\n\
  out_01: U\n\
  out_02: U\n\
  out_03: U\n\
  out_04: U\n\
  out_05: U\n\
  out_06: U\n\
  out_07: U\n\
  out_08: U\n\
  out_09: U\n\
  out_10: U\n\
  out_11: U\n\
  out_12: U\n\
  out_13: U\n\
  out_14: U\n\
  out_15: U\n\
> ");
}

TEST(tekspice, Clogger)
{
    char *args[2] = {strdup("./nano"), strdup("bonus/nts_single/logger.nts")};
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
  clock: U\n\
  in_001: U\n\
  in_002: U\n\
  in_004: U\n\
  in_008: U\n\
  in_016: U\n\
  in_032: U\n\
  in_064: U\n\
  in_128: U\n\
  inhibit: U\n\
output(s):\n\
> ");
}
