/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** NotComponent
*/

#include "Components/Elementary/NotComponent.hpp"

#include <cstddef>
#include <string>

#include "AComponent.hpp"
#include "Exceptions.hpp"
#include "tekspice.hpp"

nts::NotComponent::NotComponent(const std::string &name)
    : nts::AComponent(2, {1}, {2}, name)
{
}

nts::NotComponent::~NotComponent() = default;

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (pin > this->_nb_pins)
        throw nts::Exception("Pin is out of range");
    if (pin == 1)
        return nts::Tristate::Undefined;
    if (this->_pins.at(2).computed)
        throw nts::Exception("Infinite loop");
    this->_pins.at(2).computed = true;

    const nts::Tristate res = !updatePin(1);
    this->_pins.at(2).state = res;
    return res;
}
