/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** XorComponent
*/

#include "Components/Elementary/XorComponent.hpp"

nts::XorComponent::XorComponent(const std::string &name)
    : nts::AComponent(3, {1, 2}, {3}, name)
{
}

nts::XorComponent::~XorComponent() = default;

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
    if (pin > this->_nb_pins)
        throw std::out_of_range("Pin is out of range");
    if (pin == 1 || pin == 2)
        return nts::Tristate::Undefined;

    this->_pins.at(1).component->compute(this->_pins.at(1).pin);
    this->_pins.at(2).component->compute(this->_pins.at(2).pin);

    nts::Tristate res = this->_pins.at(1).state ^ this->_pins.at(2).state;

    this->_pins.at(3).state = res;
    return res;
}
