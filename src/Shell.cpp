/*
** EPITECH PROJECT, 2024
** tekspice
** File description:
** Shell
*/

#include "Shell.hpp"

#include <iostream>
#include <string>
#include "tekspice.hpp"

nts::Shell::Shell(IComponent* component) : _circuit(component) {}

nts::Shell::~Shell() = default;

void nts::Shell::run()
{
    _running = true;
    while (_running) {
        if (_runningCmd != LOOP)
            _runningCmd = prompt();
        runCommand();
    }
}

nts::Shell::Command nts::Shell::prompt()
{
    std::cout << "> ";

    if (!std::getline(std::cin, _input))
        return EXIT;
    for (const auto& e : COMMANDS_MATCH)
        if (std::regex_search(_input, e._pattern))
            return e._cmd;
    return UNDEFINED;
}

void nts::Shell::runCommand(nts::Shell::Command cmd)
{
    if (cmd == UNDEFINED)
        cmd = _runningCmd;
    switch (cmd) {
        case UNDEFINED:
            std::cerr << "Unknown command \"" << _input << "\"" << std::endl;
            break;
        case EXIT:
            _running = false;
            break;
        case DISPLAY:
            if (_circuit == nullptr) {
                std::cerr << "No component to display" << std::endl;
                _running = false;
                break;
            }
            _circuit->dump();
            break;
        case SIMULATE:
            if (_circuit == nullptr) {
                std::cerr << "No component to simulate" << std::endl;
                _running = false;
                break;
            }
            _circuit->simulate(1);
            break;
        case LOOP:
            if (_circuit == nullptr) {
                std::cerr << "No component to display" << std::endl;
                _running = false;
                break;
            }
            runCommand(SIMULATE);
            runCommand(DISPLAY);
            break;
        case INPUT:
            if (_circuit == nullptr) {
                std::cerr << "No component to input" << std::endl;
                _running = false;
                break;
            }

            std::string pin_name = _input.substr(0, _input.find('='));
            std::string value_str = _input.substr(_input.find('=') + 1);
            Tristate state = Undefined;
            switch (value_str[0]) {
                case '1':
                    state = True;
                    break;
                case '0':
                    state = False;
                    break;
                case 'U':
                default:
                    state = Undefined;
                    break;
            };
            try {
                _circuit->setInput(pin_name, state);
            } catch (std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
    }
}
