/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** AComponent
*/

#include "AComponent.hpp"

nts::AComponent::AComponent(size_t nb_pins, std::vector<size_t> inPins, std::vector<size_t> outPins)
    : _pins(nb_pins + 1), _nb_pins(nb_pins), _tick(0)
{
    for (int pin : inPins)
        _pins.at(pin).type = Pin::Input;
    for (int pin : outPins)
        _pins.at(pin).type = Pin::Output;
}

nts::AComponent::~AComponent()
{
}

void nts::AComponent::simulate(std::size_t /* tick */)
{
    _tick += 1;
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

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > _nb_pins)
        throw std::out_of_range("Pin is out of range");
    _pins.at(pin).component = &other;
    _pins.at(pin).pin = otherPin;
}
