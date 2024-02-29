/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** loggerComponent
*/

#include "Components/Advanced/logger.hpp"

#include <cstddef>
#include <fstream>
#include <ostream>
#include <string>

#include "AComponent.hpp"
#include "Exceptions.hpp"
#include "tekspice.hpp"

nts::loggerComponent::loggerComponent(const std::string &name)
    : nts::AComponent(10, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {}, name)
{
}

nts::loggerComponent::~loggerComponent() = default;

char nts::loggerComponent::getValue()
{
    char res = '\0';

    for (size_t i = 0; i < 8; i++) {
        res += (updatePin(i + 1) == nts::Tristate::True ? 1 : 0) << (7 - i);
    }
    return res;
}

void nts::loggerComponent::simulate(std::size_t /* tick */)
{
    if (_is_simulate)
        return;
    _is_simulate = true;

    nts::Tristate clock = updatePin(9);

    if (updatePin(10) != nts::Tristate::False) {
        _prev_c = clock;
        return;
    }
    if (_prev_c != nts::Tristate::False) {
        _prev_c = clock;
        return;
    }
    if (clock != nts::Tristate::True) {
        _prev_c = clock;
        return;
    }
    char value = this->getValue();
    std::ofstream log_file("log.bin");

    if (!log_file.is_open())
        throw nts::Exception("Error: Unable to open log file");
    log_file << value;
    log_file.close();
}

nts::Tristate nts::loggerComponent::compute(std::size_t pin)
{
    if (this->_pins.at(pin).value_set)
        return this->_pins.at(pin).state;
    if (this->_pins.at(pin).computed)
        throw nts::Exception("Infinite loop");
    this->_pins.at(pin).computed = true;
    this->simulate(0);

    return this->_pins.at(pin).state;
}
