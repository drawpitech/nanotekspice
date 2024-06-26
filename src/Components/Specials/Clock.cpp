/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** ClockComponent
*/

#include "Components/Specials/Clock.hpp"

#include <cstddef>
#include <string>

#include "AComponent.hpp"
#include "Exceptions.hpp"
#include "tekspice.hpp"

nts::ClockComponent::ClockComponent(const std::string &name)
    : nts::AComponent(1, {}, {1}, name, Input),
      _next(nts::Tristate::Undefined),
      _updated(true)
{
}

nts::ClockComponent::~ClockComponent() = default;

void nts::ClockComponent::simulate(std::size_t /* tick */)
{
    if (_is_simulate)
        return;
    _is_simulate = true;
    if (_updated) {
        _updated = false;
        this->_pins.at(1).state = _next;
        return;
    }
    this->_pins.at(1).state = !this->_pins.at(1).state;
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    this->simulate(1);
    if (pin > this->_nb_pins)
        throw nts::Exception("Pin is out of range");
    if (this->_pins.at(1).computed)
        throw nts::Exception("Pin used multiple times");
    this->_pins.at(1).computed = true;
    return this->_pins.at(1).state;
}

void nts::ClockComponent::setInput(Tristate value)
{
    this->_next = value;
    this->_updated = true;
}
