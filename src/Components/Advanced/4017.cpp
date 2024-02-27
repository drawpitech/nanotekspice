/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** C4017Component
*/

#include "Components/Advanced/4017.hpp"

#include <array>
#include <cstddef>
#include <string>

#include "AComponent.hpp"
#include "Exceptions.hpp"
#include "tekspice.hpp"

nts::C4017Component::C4017Component(const std::string &name)
    : nts::AComponent(
          15, {14, 13, 15}, {12, 3, 2, 4, 7, 10, 1, 5, 6, 9, 11}, name),
      _prev_c0(nts::Tristate::Undefined),
      _prev_c1(nts::Tristate::Undefined),
      _counter(0)
{
}

nts::C4017Component::~C4017Component() = default;

void nts::C4017Component::setValue()
{
    const std::array<size_t, 12> out_pins{3, 2, 4, 7, 10, 1, 5, 6, 9, 11};

    _counter += 1;
    for (size_t i = 0; i < 12; i++)
        _pins.at(out_pins.at(i)).state = nts::Tristate::False;
    _pins.at(out_pins.at(_counter % 10)).state = nts::Tristate::True;
    if (_counter % 10 < 5)
        _pins.at(12).state = nts::Tristate::True;
    else
        _pins.at(12).state = nts::Tristate::False;
}

void nts::C4017Component::simulate(std::size_t /* tick */)
{
    if (_is_simulate)
        return;
    _is_simulate = true;

    nts::Tristate c0 = updatePin(14);
    nts::Tristate c1 = updatePin(13);
    nts::Tristate reset = updatePin(15);

    for (auto &pin : _pins) {
        if (pin.type == Input)
            continue;
        pin.value_set = true;
    }
    if (reset == nts::Tristate::True) {
        _counter = 0;
        _pins.at(3).state = nts::Tristate::True;
        _pins.at(12).state = nts::Tristate::True;
        _pins.at(2).state = nts::Tristate::False;
        _pins.at(4).state = nts::Tristate::False;
        _pins.at(7).state = nts::Tristate::False;
        _pins.at(10).state = nts::Tristate::False;
        _pins.at(1).state = nts::Tristate::False;
        _pins.at(5).state = nts::Tristate::False;
        _pins.at(6).state = nts::Tristate::False;
        _pins.at(9).state = nts::Tristate::False;
        _pins.at(11).state = nts::Tristate::False;
    }
    if (reset == nts::Tristate::False &&
        ((_prev_c0 == nts::Tristate::False && c0 == nts::Tristate::True &&
          c1 == nts::Tristate::False) ||
         (_prev_c1 == nts::Tristate::True && c1 == nts::Tristate::False &&
          c0 == nts::Tristate::True))) {
        setValue();
    }
    _prev_c0 = c0;
    _prev_c1 = c1;
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
