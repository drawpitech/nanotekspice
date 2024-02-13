/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** NandComponent
*/

#include "Components/Elementary/NandComponent.hpp"

#include <cstddef>
#include <stdexcept>
#include <string>

#include "AComponent.hpp"
#include "tekspice.hpp"

nts::NandComponent::NandComponent(const std::string &name)
    : nts::AComponent(3, {1, 2}, {3}, name)
{
}

nts::NandComponent::~NandComponent() = default;

nts::Tristate nts::NandComponent::compute(std::size_t pin)
{
    if (pin > this->_nb_pins)
        throw std::out_of_range("Pin is out of range");
    if (pin == 1 || pin == 2)
        return nts::Tristate::Undefined;
    if (this->_pins.at(3).computed)
        throw std::out_of_range("Infinite loop");
    this->_pins.at(3).computed = true;

    const nts::Tristate res = Nand(updatePin(1), updatePin(2));
    this->_pins.at(3).state = res;
    return res;
}
