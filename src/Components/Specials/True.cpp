/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** TrueComponent
*/

#include "Components/Specials/True.hpp"

nts::TrueComponent::TrueComponent(const std::string &name)
    : nts::AComponent(1, {}, {1}, name)
{
}

nts::TrueComponent::~TrueComponent() = default;

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    if (pin > this->_nb_pins)
        throw std::out_of_range("Pin is out of range");
    this->_pins.at(1).state = nts::Tristate::True;
    return this->_pins.at(1).state;
}
