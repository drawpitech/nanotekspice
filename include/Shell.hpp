/*
** EPITECH PROJECT, 2024
** tekspice
** File description:
** Shell
*/

#pragma once

#include <regex>
#include <string>
#include <utility>
#include <vector>

namespace nts {

class Shell
{
   public:
    Shell(std::string &filename);
    ~Shell();

    void run();

    enum Command
    {
        UNDEFINED,
        EXIT,
        DISPLAY,
        INPUT,
        SIMULATE,
        LOOP,
    };

   private:
    static nts::Shell::Command prompt(std::string &buf);
    void extracted();
    void runCommand(nts::Shell::Command cmd, const std::string &buf);
    bool _running = false;
};

class CommandMatch
{
   public:
    CommandMatch(const std::string &pattern, Shell::Command cmd)
        : _cmd(cmd), _pattern(pattern)
    {
    }
    Shell::Command _cmd;
    std::regex _pattern;
};
static const std::vector<CommandMatch> COMMANDS_MATCH = {
    {R"(\bexit\b)", Shell::EXIT},
    {R"(\bdisplay\b)", Shell::DISPLAY},
    {R"(\bsimulate\b)", Shell::SIMULATE},
    {R"(\bloop\b)", Shell::LOOP},
    {R"((\w+)=(-1|0|1))", Shell::INPUT},
};
}  // namespace nts
