/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** C4094Component
*/

#include "Components/Advanced/4094.hpp"

#include <cstddef>
#include <string>

#include "AComponent.hpp"
#include "Exceptions.hpp"
#include "tekspice.hpp"

nts::C4094Component::C4094Component(const std::string &name)
    : nts::AComponent(
          16, {1, 2, 3, 15}, {9, 10, 4, 5, 6, 7, 11, 12, 13, 14}, name)
{
}

nts::C4094Component::~C4094Component() = default;

void nts::C4094Component::setValuesTrue()
{
    _pins.at(4).value_set = true;
    _pins.at(5).value_set = true;
    _pins.at(6).value_set = true;
    _pins.at(7).value_set = true;
    _pins.at(11).value_set = true;
    _pins.at(12).value_set = true;
    _pins.at(13).value_set = true;
    _pins.at(14).value_set = true;
    _pins.at(9).value_set = true;
    _pins.at(10).value_set = true;
}

void nts::C4094Component::clockUp(
    nts::Tristate enable, nts::Tristate strobe, nts::Tristate data)
{
    if (enable == nts::Tristate::Undefined ||
        strobe == nts::Tristate::Undefined)
        return;
    if (enable == nts::Tristate::False) {
        _pins.at(11).state = nts::Tristate::Undefined;
        _pins.at(12).state = nts::Tristate::Undefined;
        _pins.at(13).state = nts::Tristate::Undefined;
        _pins.at(14).state = nts::Tristate::Undefined;
        _pins.at(7).state = nts::Tristate::Undefined;
        _pins.at(6).state = nts::Tristate::Undefined;
        _pins.at(5).state = nts::Tristate::Undefined;
        _pins.at(4).state = nts::Tristate::Undefined;
        _pins.at(9).state = _pins.at(12).state;
        return;
    }
    if (strobe == nts::Tristate::False) {
        _pins.at(9).state = _pins.at(12).state;
        return;
    }
    _pins.at(11).state = _pins.at(12).state;
    _pins.at(12).state = _pins.at(13).state;
    _pins.at(13).state = _pins.at(14).state;
    _pins.at(14).state = _pins.at(7).state;
    _pins.at(7).state = _pins.at(6).state;
    _pins.at(6).state = _pins.at(5).state;
    _pins.at(5).state = _pins.at(4).state;
    _pins.at(4).state = data;
}

void nts::C4094Component::clockDown(
    nts::Tristate enable, nts::Tristate strobe, nts::Tristate /* data */)
{
    if (enable == nts::Tristate::Undefined ||
        strobe == nts::Tristate::Undefined)
        return;
    if (enable == nts::Tristate::False) {
        _pins.at(11).state = nts::Tristate::Undefined;
        _pins.at(12).state = nts::Tristate::Undefined;
        _pins.at(13).state = nts::Tristate::Undefined;
        _pins.at(14).state = nts::Tristate::Undefined;
        _pins.at(7).state = nts::Tristate::Undefined;
        _pins.at(6).state = nts::Tristate::Undefined;
        _pins.at(5).state = nts::Tristate::Undefined;
        _pins.at(4).state = nts::Tristate::Undefined;
        _pins.at(10).state = _pins.at(12).state;
        return;
    }
    if (strobe == nts::Tristate::False) {
        return;
    }
    _pins.at(10).state = _pins.at(12).state;
}

void nts::C4094Component::simulate(std::size_t /* tick */)
{
    if (_is_simulate)
        return;
    _is_simulate = true;
    nts::Tristate clock = updatePin(3);
    nts::Tristate enable = updatePin(15);
    nts::Tristate strobe = updatePin(1);
    nts::Tristate data = updatePin(2);

    setValuesTrue();
    if (_prev_clock == nts::Tristate::False && clock == nts::Tristate::True)
        clockUp(enable, strobe, data);
    if (_prev_clock == nts::Tristate::True && clock == nts::Tristate::False)
        clockDown(enable, strobe, data);
    _prev_clock = clock;
}

nts::Tristate nts::C4094Component::compute(std::size_t pin)
{
    if (this->_pins.at(pin).value_set)
        return this->_pins.at(pin).state;
    if (this->_pins.at(pin).computed)
        throw nts::Exception("Infinite loop");
    this->_pins.at(pin).computed = true;
    this->simulate(0);

    return this->_pins.at(pin).state;
}
