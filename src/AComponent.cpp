/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** AComponent
*/

#include "AComponent.hpp"

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

void nts::AComponent::dump() const
{
    std::cout << "tick: " << _tick << "\n"
              << "input(s):\n";
    for (const auto &pin : _pins)
        if (pin.type == Pin::Input)
            std::cout << pin.component->getName() << " "
                      << TRISTATE_TO_CHAR.at(pin.state) << "\n";
    std::cout << "output(s):\n";
    for (const auto &pin : _pins)
        if (pin.type == Pin::Output)
            std::cout << pin.component->getName() << " "
                      << TRISTATE_TO_CHAR.at(pin.state) << "\n";
}

std::string nts::AComponent::getName() const
{
    return _name;
}
