/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** C4514Component
*/

#include "Components/Advanced/4514.hpp"

#include <cstddef>
#include <string>

#include "AComponent.hpp"
#include "Exceptions.hpp"
#include "tekspice.hpp"

nts::C4514Component::C4514Component(const std::string &name)
    : nts::AComponent(
          24, {1, 2, 3, 21, 22, 23},
          {4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17, 18, 19, 20}, name),
      _previous_inputs({nts::Tristate::Undefined}),
      _actual_inputs({nts::Tristate::Undefined}),
      _old_strobe(nts::Tristate::Undefined)
{
}

nts::C4514Component::~C4514Component() = default;

void nts::C4514Component::setAllOutputs(nts::Tristate state)
{
    for (auto &pin : _pins) {
        if (pin.type == Input)
            continue;
        pin.state = state;
        pin.value_set = true;
    }
}

void nts::C4514Component::simulate(std::size_t /* tick */)
{
    if (_is_simulate)
        return;
    _is_simulate = true;
    nts::Tristate strobe = updatePin(1);

    _previous_inputs = _actual_inputs;
    _actual_inputs.at(0) = updatePin(2);
    _actual_inputs.at(1) = updatePin(3);
    _actual_inputs.at(2) = updatePin(21);
    _actual_inputs.at(3) = updatePin(22);

    if (updatePin(23) == nts::Tristate::True) {
        for (auto &pin : _pins)
            pin.value_set = true;
        // this->setAllOutputs(!(_pins.at(23).state));
        // _old_strobe = strobe;
        return;
    }
    if (_old_strobe == nts::Tristate::True and strobe == nts::Tristate::False) {
        size_t selector = 0;
        for (size_t i = 0; i < 4; i++) {
            selector += (_previous_inputs.at(i) == nts::Tristate::True ? 1 : 0)
                        << i;
        }
        this->setAllOutputs(nts::Tristate::False);
        _pins.at(_in_to_out.at(selector)).state = nts::Tristate::True;
    }
    for (size_t i = 0; i < 4; i++)
        if (_previous_inputs.at(i) == nts::Tristate::Undefined)
            this->setAllOutputs(nts::Tristate::Undefined);
    _old_strobe = strobe;
}

nts::Tristate nts::C4514Component::compute(std::size_t pin)
{
    if (this->_pins.at(pin).value_set) {
        if (this->_pins.at(23).state == nts::Tristate::True)
            return nts::Tristate::False;
        return this->_pins.at(pin).state;
    }
    if (this->_pins.at(pin).computed)
        throw nts::Exception("Infinite loop");
    this->_pins.at(pin).computed = true;
    this->simulate(0);

    if (this->_pins.at(23).state == nts::Tristate::True)
        return nts::Tristate::False;
    return _pins.at(pin).state;
}
