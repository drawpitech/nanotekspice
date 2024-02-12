/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** ClockComponent
*/

#include "Components/Specials/Clock.hpp"

#include <cstddef>
#include <stdexcept>
#include <string>

#include "AComponent.hpp"
#include "tekspice.hpp"

nts::ClockComponent::ClockComponent(const std::string &name)
    : nts::AComponent(1, {}, {1}, name, Input)
{
}

nts::ClockComponent::~ClockComponent() = default;

void nts::ClockComponent::simulate(std::size_t tick)
{
    if (tick == 0)
        return;
    _tick += 1;
    this->_pins.at(1).state = !this->_pins.at(1).state;
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    if (pin > this->_nb_pins)
        throw std::out_of_range("Pin is out of range");
    if (this->_pins.at(1).computed)
        throw std::out_of_range("Pin used multiple times");
    this->_pins.at(1).computed = true;
    return this->_pins.at(1).state;
}
