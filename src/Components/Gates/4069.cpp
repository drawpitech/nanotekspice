/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** SixNotComponent
*/

#include "Components/Gates/4069.hpp"

#include <cstddef>
#include <string>

#include "AComponent.hpp"
#include "Exceptions.hpp"
#include "tekspice.hpp"

nts::SixNotComponent::SixNotComponent(const std::string &name)
    : nts::AComponent(14, {1, 3, 5, 9, 11, 13}, {2, 4, 6, 8, 10, 12}, name)
{
}

nts::SixNotComponent::~SixNotComponent() = default;

nts::Tristate nts::SixNotComponent::compute(std::size_t pin)
{
    if (this->_pins.at(pin).value_set)
        return this->_pins.at(pin).state;
    if (this->_pins.at(pin).computed)
        throw nts::Exception("Infinite loop");
    this->_pins.at(pin).computed = true;

    nts::Tristate res = nts::Tristate::Undefined;
    switch (pin) {
        case 2:
        case 4:
        case 6:
            res = !updatePin(pin - 1);
            break;
        case 8:
        case 10:
        case 12:
            res = !updatePin(pin + 1);
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
