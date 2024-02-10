/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** InputComponent
*/

#include "Components/Specials/Input.hpp"

nts::InputComponent::InputComponent(const std::string &name)
    : nts::AComponent(1, {}, {1}, name), _next(nts::Tristate::Undefined)
{
}

nts::InputComponent::~InputComponent() = default;

void nts::InputComponent::simulate(std::size_t tick)
{
    if (tick == 0)
        return;
    _tick += 1;
    this->_pins.at(1).state = _next;
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin > this->_nb_pins)
        throw std::out_of_range("Pin is out of range");
    return this->_pins.at(1).state;
}
