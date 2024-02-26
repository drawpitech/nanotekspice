/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** C4008Component
*/

#include "Components/Advanced/4008.hpp"

#include <cstddef>
#include <stdexcept>
#include <string>

#include "AComponent.hpp"
#include "tekspice.hpp"

nts::C4008Component::C4008Component(const std::string &name)
    : nts::AComponent(
          16, {1, 2, 3, 4, 5, 6, 7, 9, 15}, {10, 11, 12, 13, 14}, name)
{
}

nts::C4008Component::~C4008Component() = default;

nts::Tristate nts::C4008Component::addPins(
    nts::Tristate p1, nts::Tristate p2, nts::Tristate &carry)
{
    if (p1 == nts::Tristate::Undefined || p2 == nts::Tristate::Undefined ||
        carry == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;

    nts::Tristate res = carry;
    if (p1 == p2) {
        carry = p1;
        return res;
    }
    return !res;
}

void nts::C4008Component::simulate(std::size_t /* tick */)
{
    if (_is_simulate)
        return;
    _is_simulate = true;
    nts::Tristate c = updatePin(9);
    _pins.at(10).state = addPins(updatePin(6), updatePin(7), c);
    _pins.at(10).value_set = true;
    _pins.at(11).state = addPins(updatePin(4), updatePin(5), c);
    _pins.at(11).value_set = true;
    _pins.at(12).state = addPins(updatePin(2), updatePin(3), c);
    _pins.at(12).value_set = true;
    _pins.at(13).state = addPins(updatePin(15), updatePin(1), c);
    _pins.at(13).value_set = true;
    _pins.at(14).state = c;
    _pins.at(14).value_set = true;
}

nts::Tristate nts::C4008Component::compute(std::size_t pin)
{
    this->_pins.at(pin).computed = true;
    if (this->_pins.at(pin).value_set)
        return this->_pins.at(pin).state;
    if (this->_pins.at(pin).computed)
        throw std::out_of_range("Infinite loop");
    this->simulate(0);

    return _pins.at(pin).state;
}
