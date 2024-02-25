/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** C4013Component
*/

#include "Components/Advanced/4013.hpp"

#include <cstddef>
#include <stdexcept>
#include <string>

#include "AComponent.hpp"
#include "tekspice.hpp"

nts::C4013Component::C4013Component(const std::string &name)
    : nts::AComponent(14, {3, 5, 6, 4, 9, 8, 10, 11}, {1, 2, 12, 13}, name)
{
}

nts::C4013Component::~C4013Component() = default;

void nts::C4013Component::computeFF(std::array<size_t, 6> pins)
{
    nts::Tristate data = updatePin(pins.at(0));
    nts::Tristate set = updatePin(pins.at(1));
    nts::Tristate reset = updatePin(pins.at(2));
    nts::Tristate clock = updatePin(pins.at(3));
    size_t Q = pins.at(4);
    size_t Qb = pins.at(5);

    _pins.at(Q).state = nts::Tristate::Undefined;
    _pins.at(Qb).state = nts::Tristate::Undefined;
    if (reset == nts::Tristate::Undefined || set == nts::Tristate::Undefined)
        return;
    if (reset == nts::Tristate::True || set == nts::Tristate::True) {
        _pins.at(Q).state = set;
        _pins.at(Qb).state = reset;
        return;
    }
    if (clock != nts::Tristate::True)
        return;
    _pins.at(Q).state = data;
    _pins.at(Qb).state = !data;
}

void nts::C4013Component::simulate(std::size_t /* tick */)
{
    if (_is_simulate)
        return;
    _is_simulate = true;
    this->computeFF({5, 6, 4, 3, 1, 2});
    this->computeFF({9, 8, 10, 11, 13, 12});
}

nts::Tristate nts::C4013Component::compute(std::size_t pin)
{
    this->simulate(0);
    if (this->_pins.at(pin).computed)
        throw std::out_of_range("Infinite loop");

    this->_pins.at(pin).computed = true;
    return _pins.at(pin).state;
}
