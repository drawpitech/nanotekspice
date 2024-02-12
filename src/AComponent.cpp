/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** AComponent
*/

#include "AComponent.hpp"

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "tekspice.hpp"

nts::AComponent::AComponent(
    size_t nb_pins, std::vector<size_t> inPins, std::vector<size_t> outPins,
    std::string name, Type type)
    : _pins(nb_pins + 1),
      _nb_pins(nb_pins),
      _tick(0),
      _name(std::move(name)),
      _type(type)
{
    for (auto pin : inPins)
        _pins.at(pin).type = Input;
    for (auto pin : outPins)
        _pins.at(pin).type = Output;
}

nts::AComponent::~AComponent() = default;

void nts::AComponent::simulate(std::size_t tick)
{
    _tick += tick;
}

nts::Tristate nts::AComponent::compute(size_t pin)
{
    if (pin > _nb_pins)
        throw std::out_of_range("Pin is out of range");
    if (_pins.at(pin).component == nullptr)
        throw std::out_of_range("This pin is not set it should not append");
    if (_pins.at(pin).type == Output)
        return _pins.at(pin).state;
    if (_pins.at(pin).type == Input)
        return _pins.at(pin).component->compute(_pins.at(pin).pin);
    return nts::Tristate::Undefined;
}

nts::Tristate nts::AComponent::getPinValue(std::size_t pin) const
{
    if (pin > _nb_pins)
        throw std::out_of_range("Pin is out of range");
    return this->_pins.at(pin).state;
}

void nts::AComponent::setLink(
    std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > _nb_pins)
        throw std::out_of_range("Pin is out of range");
    _pins.at(pin).component = &other;
    _pins.at(pin).pin = otherPin;
}

static std::vector<nts::Pin> get_pins(
    std::vector<nts::Pin> pins, nts::Type type)
{
    std::vector<nts::Pin> ret;
    std::copy_if(
        pins.begin(), pins.end(), std::back_inserter(ret),
        [type](const nts::Pin &pin) { return pin.type == type; });
    std::sort(
        pins.begin(), pins.end(), [](const nts::Pin &a, const nts::Pin &b) {
            return a.component->getName() < b.component->getName();
        });
    return ret;
}

void nts::AComponent::dump() const
{
    std::cout << "tick: " << _tick << "\n"
              << "input(s):\n";

    for (const auto &pin : get_pins(_pins, Input))
        if (pin.type == Input)
            std::cout << "  " << pin.component->getName() << " "
                      << TRISTATE_TO_CHAR.at(pin.state) << "\n";
    std::cout << "output(s):\n";
    for (const auto &pin : get_pins(_pins, Output))
        if (pin.type == Output)
            std::cout << "  " << pin.component->getName() << ": "
                      << TRISTATE_TO_CHAR.at(pin.state) << "\n";
}

nts::Type nts::AComponent::getType() const
{
    return _type;
}

std::string nts::AComponent::getName() const
{
    return _name;
}

void nts::AComponent::setInput(nts::Tristate /* value */)
{
    throw std::out_of_range(
        "This method should't be called if component is not an input");
}

void nts::AComponent::reset_pins()
{
    for (auto pin : _pins) {
        pin.computed = false;
    }
}
