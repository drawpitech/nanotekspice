/*
** EPITECH PROJECT, 2024
** tekspice
** File description:
** Shell
*/

#pragma once

#include <map>
#include <string>

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
    void runCommand(nts::Shell::Command cmd, const std::string &buf);
    bool _running = false;
};

static const std::map<std::string, Shell::Command> commands = {
    {"exit", Shell::EXIT},
    {"display", Shell::DISPLAY},
    {"simulate", Shell::SIMULATE},
    {"loop", Shell::LOOP},
};
}  // namespace nts
