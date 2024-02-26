/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** NorComponent
*/

#include "Components/Elementary/NorComponent.hpp"

#include <cstddef>
#include <string>

#include "AComponent.hpp"
#include "Exceptions.hpp"
#include "tekspice.hpp"

nts::NorComponent::NorComponent(const std::string &name)
    : nts::AComponent(3, {1, 2}, {3}, name)
{
}

nts::NorComponent::~NorComponent() = default;

nts::Tristate nts::NorComponent::compute(std::size_t pin)
{
    if (pin > this->_nb_pins)
        throw nts::Exception("Pin is out of range");
    if (pin == 1 || pin == 2)
        return nts::Tristate::Undefined;
    if (this->_pins.at(3).computed)
        throw nts::Exception("Infinite loop");
    this->_pins.at(3).computed = true;

    const nts::Tristate res = Nor(updatePin(1), updatePin(2));
    this->_pins.at(3).state = res;
    return res;
}
