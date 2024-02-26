/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** FourXorComponent
*/

#include "Components/Gates/4030.hpp"

#include <cstddef>
#include <string>

#include "AComponent.hpp"
#include "Exceptions.hpp"
#include "tekspice.hpp"

nts::FourXorComponent::FourXorComponent(const std::string &name)
    : nts::AComponent(14, {1, 2, 5, 6, 8, 9, 12, 13}, {3, 4, 10, 11}, name)
{
}

nts::FourXorComponent::~FourXorComponent() = default;

nts::Tristate nts::FourXorComponent::compute(std::size_t pin)
{
    if (this->_pins.at(pin).value_set)
        return this->_pins.at(pin).state;
    if (this->_pins.at(pin).computed)
        throw nts::Exception("Infinite loop");
    this->_pins.at(pin).computed = true;

    nts::Tristate res = nts::Tristate::Undefined;
    switch (pin) {
        case 3:
        case 10:
            res = updatePin(pin - 1) ^ updatePin(pin - 2);
            break;
        case 4:
        case 11:
            res = updatePin(pin + 1) ^ updatePin(pin + 2);
            break;
        case 7:
        case 14:
            res = nts::Tristate::Undefined;
            break;
        default:
            throw nts::Exception("This is not an output pin");
            break;
    }
    this->_pins.at(pin).state = res;
    this->_pins.at(pin).value_set = true;
    return res;
}
