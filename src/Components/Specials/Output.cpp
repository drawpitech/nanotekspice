/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** OutputComponent
*/

#include "Components/Specials/Output.hpp"

#include <cstddef>
#include <string>

#include "AComponent.hpp"
#include "Exceptions.hpp"
#include "tekspice.hpp"

nts::OutputComponent::OutputComponent(const std::string &name)
    : nts::AComponent(2, {1}, {2}, name, Output)
{
}

nts::OutputComponent::~OutputComponent() = default;

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin > this->_nb_pins)
        throw nts::Exception("Pin is out of range");

    const nts::Tristate res = updatePin(1);
    this->_pins.at(2).state = res;
    return res;
}
