/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** C4017Component
*/

#include "Components/Advanced/4017.hpp"

#include <cstddef>
#include <string>

#include "AComponent.hpp"
#include "Exceptions.hpp"
#include "tekspice.hpp"

nts::C4017Component::C4017Component(const std::string &name)
    : nts::AComponent(
          15, {14, 13, 15}, {12, 3, 2, 4, 7, 10, 1, 5, 6, 9, 11}, name)
{
}

nts::C4017Component::~C4017Component() = default;

void nts::C4017Component::simulate(std::size_t /* tick */)
{
    if (_is_simulate)
        return;
    _is_simulate = true;
}

nts::Tristate nts::C4017Component::compute(std::size_t pin)
{
    if (this->_pins.at(pin).value_set)
        return this->_pins.at(pin).state;
    if (this->_pins.at(pin).computed)
        throw nts::Exception("Infinite loop");
    this->_pins.at(pin).computed = true;
    this->simulate(0);

    return _pins.at(pin).state;
}
