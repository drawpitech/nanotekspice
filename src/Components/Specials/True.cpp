/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** TrueComponent
*/

#include "Components/Specials/True.hpp"

#include <cstddef>
#include <string>

#include "AComponent.hpp"
#include "Exceptions.hpp"
#include "tekspice.hpp"

nts::TrueComponent::TrueComponent(const std::string &name)
    : nts::AComponent(1, {}, {1}, name, nts::Other)
{
    this->_pins.at(1).state = nts::Tristate::True;
}

nts::TrueComponent::~TrueComponent() = default;

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    if (pin > this->_nb_pins)
        throw nts::Exception("Pin is out of range");
    if (this->_pins.at(1).computed)
        throw nts::Exception("Pin used multiple times");
    this->_pins.at(1).computed = true;
    return nts::Tristate::True;
}
