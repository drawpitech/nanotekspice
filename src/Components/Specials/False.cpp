/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** FalseComponent
*/

#include "Components/Specials/False.hpp"

#include <cstddef>
#include <stdexcept>
#include <string>

#include "AComponent.hpp"
#include "tekspice.hpp"
nts::FalseComponent::FalseComponent(const std::string &name)
    : nts::AComponent(1, {}, {1}, name)
{
}

nts::FalseComponent::~FalseComponent() = default;

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    if (pin > this->_nb_pins)
        throw std::out_of_range("Pin is out of range");
    if (this->_pins.at(1).computed)
        throw std::out_of_range("Pin used multiple times");
    this->_pins.at(1).computed = true;

    this->_pins.at(1).state = nts::Tristate::False;
    return this->_pins.at(1).state;
}
