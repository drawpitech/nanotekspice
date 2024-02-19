/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** InputComponent
*/

#include "Components/Specials/Input.hpp"

#include <cstddef>
#include <stdexcept>
#include <string>

#include "AComponent.hpp"
#include "tekspice.hpp"

nts::InputComponent::InputComponent(const std::string &name)
    : nts::AComponent(1, {}, {1}, name, Input), _next(nts::Tristate::Undefined)
{
}

nts::InputComponent::~InputComponent() = default;

void nts::InputComponent::simulate(std::size_t /* tick */)
{
    if (_is_simulate)
        return;
    _is_simulate = true;
    _tick += 1;
    this->_pins.at(1).state = _next;
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    this->simulate(1);
    if (pin > this->_nb_pins)
        throw std::out_of_range("Pin is out of range");
    if (this->_pins.at(1).computed)
        throw std::out_of_range("Pin used multiple times");
    this->_pins.at(1).computed = true;

    return this->_pins.at(1).state;
}

void nts::InputComponent::setInput(Tristate value)
{
    this->_next = value;
}
