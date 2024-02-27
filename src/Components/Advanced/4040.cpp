/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** C4040Component
*/

#include "Components/Advanced/4040.hpp"

#include <array>
#include <bitset>
#include <cstddef>
#include <string>

#include "AComponent.hpp"
#include "Exceptions.hpp"
#include "tekspice.hpp"

nts::C4040Component::C4040Component(const std::string &name)
    : nts::AComponent(
          16, {10, 11}, {9, 7, 6, 5, 3, 2, 4, 13, 12, 14, 15, 1}, name),
      _counter(0),
      _prev_clock(nts::Tristate::Undefined)
{
}

nts::C4040Component::~C4040Component() = default;

void nts::C4040Component::addCount()
{
    const std::array<size_t, 12> out_pins{9, 7,  6,  5,  3,  2,
                                          4, 13, 12, 14, 15, 1};

    _counter += 1;
    std::bitset<12> counter_bits{_counter};
    for (size_t i = 0; i < 12; i++)
        _pins.at(out_pins.at(i)).state =
            counter_bits[i] ? nts::Tristate::True : nts::Tristate::False;
}

void nts::C4040Component::simulate(std::size_t /* tick */)
{
    if (_is_simulate)
        return;
    _is_simulate = true;
    nts::Tristate clock = updatePin(10);
    nts::Tristate reset = updatePin(11);

    if (reset == nts::Tristate::True) {
        _counter = 0;
        for (auto &pin : _pins) {
            if (pin.type == Input)
                continue;
            pin.state = nts::Tristate::False;
            pin.value_set = true;
        }
    }
    if (reset == nts::Tristate::False && _prev_clock == nts::Tristate::True &&
        clock == nts::Tristate::False) {
        addCount();
    }
    _prev_clock = clock;
}

nts::Tristate nts::C4040Component::compute(std::size_t pin)
{
    this->simulate(0);
    if (this->_pins.at(pin).value_set)
        return this->_pins.at(pin).state;
    if (this->_pins.at(pin).computed)
        throw nts::Exception("Infinite loop");

    this->_pins.at(pin).computed = true;
    return this->_pins.at(pin).state;
}
