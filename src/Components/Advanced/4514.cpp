/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** C4514Component
*/

#include "Components/Advanced/4514.hpp"

#include <cstddef>
#include <stdexcept>
#include <string>

#include "AComponent.hpp"
#include "tekspice.hpp"

nts::C4514Component::C4514Component(const std::string &name)
    : nts::AComponent(
          24, {1, 2, 3, 21, 22, 23},
          {4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17, 18, 19, 20}, name),
      _previous_inputs({nts::Tristate::Undefined}),
      _actual_inputs({nts::Tristate::Undefined})

{
}

nts::C4514Component::~C4514Component() = default;

void nts::C4514Component::simulate(std::size_t /* tick */)
{
    if (_is_simulate)
        return;
    _is_simulate = true;
    nts::Tristate Strobe = updatePin(1);
    if (Strobe == nts::Tristate::Undefined)
        return;
    if (Strobe == nts::Tristate::True) {
        _previous_inputs = _actual_inputs;
        _actual_inputs.at(0) = updatePin(2);
        _actual_inputs.at(1) = updatePin(3);
        _actual_inputs.at(2) = updatePin(21);
        _actual_inputs.at(3) = updatePin(22);
        return;
    }
    if (updatePin(23) != nts::Tristate::False) {
        for (auto &pin : _pins) {
            if (pin.type == Input)
                continue;
            pin.state = _pins.at(23).state;
            pin.value_set = true;
        }
        return;
    }

    size_t selector =
        (_previous_inputs.at(0) == nts::Tristate::True ? 1 : 0) +
        ((_previous_inputs.at(1) == nts::Tristate::True ? 1 : 0) << 1) +
        ((_previous_inputs.at(2) == nts::Tristate::True ? 1 : 0) << 2) +
        ((_previous_inputs.at(3) == nts::Tristate::True ? 1 : 0) << 3);
    for (auto &pin : _pins) {
        if (pin.type == Input)
            continue;
        pin.state = nts::Tristate::False;
        pin.value_set = true;
    }
    _pins.at(_in_to_out.at(selector)).state = nts::Tristate::True;
}

nts::Tristate nts::C4514Component::compute(std::size_t pin)
{
    this->simulate(0);
    if (this->_pins.at(pin).computed)
        throw std::out_of_range("Infinite loop");

    nts::Tristate res = _pins.at(pin).state;

    this->_pins.at(pin).computed = true;
    this->_pins.at(pin).state = res;
    return res;
}
