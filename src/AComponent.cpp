/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** AComponent
*/

#include "AComponent.hpp"

#include <algorithm>
#include <iostream>
#include <utility>

nts::AComponent::AComponent(
    size_t nb_pins, std::vector<size_t> inPins, std::vector<size_t> outPins,
    std::string name)
    : _pins(nb_pins + 1), _nb_pins(nb_pins), _tick(0), _name(std::move(name))
{
    for (auto pin : inPins)
        _pins.at(pin).type = Pin::Input;
    for (auto pin : outPins)
        _pins.at(pin).type = Pin::Output;
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
    if (_pins.at(pin).type == Pin::Output)
        return _pins.at(pin).state;
    if (_pins.at(pin).type == Pin::Input)
        return _pins.at(pin).component->compute(_pins.at(pin).pin);
    return nts::Undefined;
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
    std::vector<nts::Pin> pins, nts::Pin::Type type)
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

    for (const auto &pin : get_pins(_pins, Pin::Input))
        if (pin.type == Pin::Input)
            std::cout << "  " << pin.component->getName() << " "
                      << TRISTATE_TO_CHAR.at(pin.state) << "\n";
    std::cout << "output(s):\n";
    for (const auto &pin : get_pins(_pins, Pin::Output))
        if (pin.type == Pin::Output)
            std::cout << "  " << pin.component->getName() << ": "
                      << TRISTATE_TO_CHAR.at(pin.state) << "\n";
}

std::string nts::AComponent::getName() const
{
    return _name;
}

void nts::AComponent::setInput(std::string pin_name, nts::Tristate value)
{
    auto it = std::find_if(
        _pins.begin(), _pins.end(), [pin_name](const nts::Pin &pin) {
            return (pin.component != nullptr) &&
                   pin.component->getName() == pin_name;
        });
    if (it == _pins.end())
        throw std::out_of_range("Pin not found");
    setInput(it->pin, value);
}

void nts::AComponent::setInput(size_t pin, nts::Tristate value)
{
    if (pin > _nb_pins)
        throw std::out_of_range("Pin is out of range");
    _pins.at(pin).state = value;
}
