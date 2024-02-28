/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** C4013Component
*/

#include "Components/Advanced/4013.hpp"

#include <cstddef>
#include <string>

#include "AComponent.hpp"
#include "Exceptions.hpp"
#include "tekspice.hpp"

nts::C4013Component::C4013Component(const std::string &name)
    : nts::AComponent(14, {3, 5, 6, 4, 9, 8, 10, 11}, {1, 2, 12, 13}, name)
{
}

nts::C4013Component::~C4013Component() = default;

void nts::C4013Component::computeFF(std::array<size_t, 6> pins, bool flipflop1)
{
    nts::Tristate data = updatePin(pins.at(0));
    nts::Tristate set = updatePin(pins.at(1));
    nts::Tristate reset = updatePin(pins.at(2));
    nts::Tristate clock = updatePin(pins.at(3));
    size_t Q = pins.at(4);
    size_t Qb = pins.at(5);

    _pins.at(Q).value_set = true;
    _pins.at(Qb).value_set = true;
    if (reset == nts::Tristate::Undefined || set == nts::Tristate::Undefined)
        return;
    if (reset == nts::Tristate::True || set == nts::Tristate::True) {
        _pins.at(Q).state = set;
        _pins.at(Qb).state = reset;
        return;
    }
    if (flipflop1) {
        if (clock == _prev_c1 || _prev_c1 == nts::Tristate::True)
            return;
    } else {
        if (clock == _prev_c2 || _prev_c2 == nts::Tristate::True)
            return;
    }

    _pins.at(Q).state = data;
    _pins.at(Qb).state = !data;
}

void nts::C4013Component::simulate(std::size_t /* tick */)
{
    if (_is_simulate)
        return;
    _is_simulate = true;
    this->computeFF({5, 6, 4, 3, 1, 2}, true);
    this->computeFF({9, 8, 10, 11, 13, 12}, false);
    _prev_c1 = _pins.at(3).state;
    _prev_c2 = _pins.at(11).state;
}

nts::Tristate nts::C4013Component::compute(std::size_t pin)
{
    if (this->_pins.at(pin).value_set)
        return this->_pins.at(pin).state;
    if (this->_pins.at(pin).computed)
        throw nts::Exception("Infinite loop");
    this->_pins.at(pin).computed = true;
    this->simulate(0);

    return _pins.at(pin).state;
}
