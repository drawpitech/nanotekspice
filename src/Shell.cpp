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
    std::string buf;

    _running = true;
    while (_running) {
        runCommand(prompt(buf), buf);
    }
}

nts::Shell::Command nts::Shell::prompt(std::string& buf)
{
    std::cout << "> ";

    if (!std::getline(std::cin, buf)) {
        std::cout << "\n";
        return EXIT;
    }
    if (commands.find(buf) != commands.end())
        return commands.at(buf);
    if (buf.find('=') != std::string::npos)
        return INPUT;
    return UNDEFINED;
}

void nts::Shell::runCommand(nts::Shell::Command cmd, const std::string& buf)
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
            std::string input = buf.substr(0, buf.find('='));
            std::string raw_value = buf.substr(buf.find('=') + 1);
            if (input.empty()) {
                std::cerr << "Invalid input" << std::endl;
                return;
            }

            int value = 0;
            bool is_valid = true;
            try {
                value = std::stoi(raw_value);
            } catch (std::exception& e) {
                is_valid = false;
            }
            if (is_valid && (value < -1 || value > 1)) {
                std::cerr << "Invalid value" << std::endl;
                return;
            }

            std::cout << "var: " << input << "\nvalue: " << value << "\n";
            // TODO
            break;
    }
}
