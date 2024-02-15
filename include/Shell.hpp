/*
** EPITECH PROJECT, 2024
** tekspice
** File description:
** Shell
*/

#pragma once

#include <regex>
#include <string>
#include <vector>

#include "Circuit.hpp"

namespace nts {

class Shell
{
   public:
    Shell(Circuit *circuit);
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
    nts::Shell::Command prompt();
    void extracted();
    void runCommand(nts::Shell::Command cmd);

    std::string _input;
    bool _running = false;
    Circuit *_circuit;

    void Exit();
    void Display();
    void Input();
    void Simulate();
    void Loop();
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
    {R"(^exit$)", Shell::EXIT},
    {R"(^display$)", Shell::DISPLAY},
    {R"(^simulate$)", Shell::SIMULATE},
    {R"(^loop$)", Shell::LOOP},
    {R"(^\w+=[U01]$)", Shell::INPUT},
};
}  // namespace nts
