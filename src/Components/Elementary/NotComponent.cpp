/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** NotComponent
*/

#include "Components/Elementary/NotComponent.hpp"

#include <cstddef>
#include <stdexcept>
#include <string>

#include "AComponent.hpp"
#include "tekspice.hpp"

nts::NotComponent::NotComponent(const std::string &name)
    : nts::AComponent(2, {1}, {2}, name)
{
}

nts::NotComponent::~NotComponent() = default;

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (pin > this->_nb_pins)
        throw std::out_of_range("Pin is out of range");
    if (pin == 1)
        return nts::Tristate::Undefined;
    if (this->_pins.at(2).computed)
        throw std::out_of_range("Infinite loop");
    this->_pins.at(2).computed = true;

    this->_pins.at(1).component->compute(this->_pins.at(1).pin);

    const nts::Tristate res = !this->_pins.at(1).state;

    this->_pins.at(2).state = res;
    return res;
}
