/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** OrComponent
*/

#include "Components/Elementary/OrComponent.hpp"

#include <cstddef>
#include <stdexcept>
#include <string>

#include "AComponent.hpp"
#include "tekspice.hpp"

nts::OrComponent::OrComponent(const std::string &name)
    : nts::AComponent(3, {1, 2}, {3}, name)
{
}

nts::OrComponent::~OrComponent() = default;

nts::Tristate nts::OrComponent::compute(std::size_t pin)
{
    if (pin > this->_nb_pins)
        throw std::out_of_range("Pin is out of range");
    if (pin == 1 || pin == 2)
        return nts::Tristate::Undefined;
    if (this->_pins.at(3).computed)
        throw std::out_of_range("Infinite loop");
    this->_pins.at(3).computed = true;

    const nts::Tristate res = updatePin(1) || updatePin(2);
    this->_pins.at(3).state = res;
    return res;
}
