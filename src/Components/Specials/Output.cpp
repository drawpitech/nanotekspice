/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** OutputComponent
*/

#include "Components/Specials/Output.hpp"

#include <cstddef>
#include <stdexcept>
#include <string>

#include "AComponent.hpp"
#include "tekspice.hpp"

nts::OutputComponent::OutputComponent(const std::string &name)
    : nts::AComponent(2, {1}, {2}, name, Output)
{
}

nts::OutputComponent::~OutputComponent() = default;

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin > this->_nb_pins)
        throw std::out_of_range("Pin is out of range");
    this->_pins.at(1).component->compute(this->_pins.at(1).pin);

    const nts::Tristate res = !this->_pins.at(1).state;

    this->_pins.at(2).state = res;
    return res;
}
