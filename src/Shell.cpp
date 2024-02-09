/*
** EPITECH PROJECT, 2024
** tekspice
** File description:
** Shell
*/

#include "Shell.hpp"

#include <iostream>
#include <string>

nts::Shell::Shell(std::string& /*filename*/) {}

nts::Shell::~Shell() = default;

void nts::Shell::run()
{
    _running = true;
    while (_running)
        runCommand(prompt());
}

nts::Shell::Command nts::Shell::prompt()
{
    std::cout << "> ";

    if (!std::getline(std::cin, _input)) {
        std::cout << "\n";
        return EXIT;
    }
    for (const auto& e : COMMANDS_MATCH)
        if (std::regex_search(_input, e._pattern))
            return e._cmd;
    return UNDEFINED;
}

void nts::Shell::runCommand(nts::Shell::Command cmd)
{
    switch (cmd) {
        case UNDEFINED:
            std::cerr << "Unknown command" << std::endl;
            _running = false;
            break;
        case EXIT:
            _running = false;
            break;
        case DISPLAY:
        case SIMULATE:
        case LOOP:
            // TODO
            break;
        case INPUT:
            std::string input = _input.substr(0, _input.find('='));
            std::string raw_value = _input.substr(_input.find('=') + 1);
            if (input.empty()) {
                std::cerr << "Invalid input" << std::endl;
                return;
            }

            int value = 0;
            try {
                value = std::stoi(raw_value);
            } catch (std::exception& e) {
                std::cerr << "Invalid value" << std::endl;
                return;
            }
            std::cout << "var: " << input << "\nvalue: " << value << "\n";
            // TODO
            break;
    }
}
