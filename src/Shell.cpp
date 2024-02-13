/*
** EPITECH PROJECT, 2024
** tekspice
** File description:
** Shell
*/

#include "Shell.hpp"

#include <csignal>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Circuit.hpp"
#include "tekspice.hpp"

nts::Shell::Shell(Circuit* circuit) : _circuit(circuit) {}

nts::Shell::~Shell() = default;

void nts::Shell::run()
{
    _running = true;
    while (_running) {
        nts::Shell::Command cmd = prompt();
        runCommand(cmd);
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
    if (_circuit == nullptr) {
        std::cerr << "Circuit is undefined" << std::endl;
        _running = false;
        return;
    }

    switch (cmd) {
        case UNDEFINED:
            std::cerr << "Unknown command \"" << _input << "\"" << std::endl;
            break;
        case EXIT:
            Exit();
            break;
        case DISPLAY:
            Display();
            break;
        case SIMULATE:
            Simulate();
            break;
        case LOOP:
            Loop();
            break;
        case INPUT:
            Input();
            break;
    }
}

void nts::Shell::Exit()
{
    _running = false;
}

void nts::Shell::Display()
{
    _circuit->dump();
}

void nts::Shell::Simulate()
{
    _circuit->simulate(1);
}

static volatile bool looping = false;
void nts::Shell::Loop()
{
    looping = true;
    std::signal(SIGINT, [](int /**/) { looping = false; });
    while (looping) {
        Simulate();
        Display();
    }
}

void nts::Shell::Input()
{
    if (_circuit == nullptr) {
        std::cerr << "No component to input" << std::endl;
        _running = false;
        return;
    }

    const std::string& pin_name = _input.substr(0, _input.find('='));
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
        (void)state;
        _circuit->getComponent(pin_name).setInput(state);
    } catch (std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
}
