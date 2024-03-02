/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** test_tekspice
*/

#include <gtest/gtest.h>

#include "tekspice.hpp"

TEST(tekspice, no_file_specified)
{
    char *name = strdup("./nano");
    EXPECT_EQ(nts::tekspice(1, &name), 84);
    // EXPECT_THROW(nts::tekspice(1, {"./nano"}), nts::Exception);
}

TEST(tekspice, single_and_gate)
{
    char *args[2] = {strdup("./nano"), strdup("bonus/nts_single/and.nts")};

    std::istringstream iss("display\n");
    std::streambuf *cinBackup = std::cin.rdbuf(iss.rdbuf());  // Redirect cin
    testing::internal::CaptureStdout();
    EXPECT_EQ(nts::tekspice(2, args), 0);
    std::string output = testing::internal::GetCapturedStdout();
    std::cin.rdbuf(cinBackup);
    EXPECT_EQ(
        output,
        "> tick: 0\ninput(s):\n  in_1: U\n  in_2: U\noutput(s):\n  out: U\n> ");
}

TEST(tekspice, single_or_gate)
{
    char *args[2] = {strdup("./nano"), strdup("bonus/nts_single/or.nts")};
    std::istringstream iss("display\n");
    std::streambuf *cinBackup = std::cin.rdbuf(iss.rdbuf());  // Redirect cin

    testing::internal::CaptureStdout();
    EXPECT_EQ(nts::tekspice(2, args), 0);
    std::string output = testing::internal::GetCapturedStdout();
    std::cin.rdbuf(cinBackup);
    EXPECT_EQ(
        output,
        "> tick: 0\ninput(s):\n  in_1: U\n  in_2: U\noutput(s):\n  out: U\n> ");
}

TEST(tekspice, single_xor_gate)
{
    char *args[2] = {strdup("./nano"), strdup("bonus/nts_single/xor.nts")};
    std::istringstream iss("display\n");
    std::streambuf *cinBackup = std::cin.rdbuf(iss.rdbuf());  // Redirect cin

    testing::internal::CaptureStdout();
    EXPECT_EQ(nts::tekspice(2, args), 0);
    std::string output = testing::internal::GetCapturedStdout();
    std::cin.rdbuf(cinBackup);
    EXPECT_EQ(
        output,
        "> tick: 0\ninput(s):\n  in_1: U\n  in_2: U\noutput(s):\n  out: U\n> ");
}

TEST(tekspice, single_not_gate)
{
    char *args[2] = {strdup("./nano"), strdup("bonus/nts_single/not.nts")};
    std::istringstream iss("display\n");
    std::streambuf *cinBackup = std::cin.rdbuf(iss.rdbuf());  // Redirect cin

    testing::internal::CaptureStdout();
    EXPECT_EQ(nts::tekspice(2, args), 0);
    std::string output = testing::internal::GetCapturedStdout();
    std::cin.rdbuf(cinBackup);
    EXPECT_EQ(
        output, "> tick: 0\ninput(s):\n  in: U\noutput(s):\n  out: U\n> ");
}

TEST(tekspice, single_clock)
{
    char *args[2] = {strdup("./nano"), strdup("bonus/nts_single/clock.nts")};
    std::istringstream iss("display\n");
    std::streambuf *cinBackup = std::cin.rdbuf(iss.rdbuf());  // Redirect cin

    testing::internal::CaptureStdout();
    EXPECT_EQ(nts::tekspice(2, args), 0);
    std::string output = testing::internal::GetCapturedStdout();
    std::cin.rdbuf(cinBackup);
    EXPECT_EQ(
        output, "> tick: 0\ninput(s):\n  cl: U\noutput(s):\n  out: U\n> ");
}

TEST(tekspice, single_true)
{
    char *args[2] = {strdup("./nano"), strdup("bonus/nts_single/true.nts")};
    std::istringstream iss("display\n");
    std::streambuf *cinBackup = std::cin.rdbuf(iss.rdbuf());  // Redirect cin

    testing::internal::CaptureStdout();
    EXPECT_EQ(nts::tekspice(2, args), 0);
    std::string output = testing::internal::GetCapturedStdout();
    std::cin.rdbuf(cinBackup);
    EXPECT_EQ(output, "> tick: 0\ninput(s):\noutput(s):\n  out: 1\n> ");
}

TEST(tekspice, single_false)
{
    char *args[2] = {strdup("./nano"), strdup("bonus/nts_single/false.nts")};
    std::istringstream iss("display\n");
    std::streambuf *cinBackup = std::cin.rdbuf(iss.rdbuf());  // Redirect cin

    testing::internal::CaptureStdout();
    EXPECT_EQ(nts::tekspice(2, args), 0);
    std::string output = testing::internal::GetCapturedStdout();
    std::cin.rdbuf(cinBackup);
    EXPECT_EQ(output, "> tick: 0\ninput(s):\noutput(s):\n  out: 0\n> ");
}
