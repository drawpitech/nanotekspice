/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** FalseComponent
*/

#include "Components/Specials/False.hpp"

nts::FalseComponent::FalseComponent(const std::string &name)
    : nts::AComponent(1, {}, {1}, name)
{
}

nts::FalseComponent::~FalseComponent() = default;

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    if (pin > this->_nb_pins)
        throw std::out_of_range("Pin is out of range");
    this->_pins.at(1).state = nts::Tristate::False;
    return this->_pins.at(1).state;
}
