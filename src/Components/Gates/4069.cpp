/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** SixNotComponent
*/

#include "Components/Gates/4069.hpp"

#include <cstddef>
#include <stdexcept>
#include <string>

#include "AComponent.hpp"
#include "tekspice.hpp"

nts::SixNotComponent::SixNotComponent(const std::string &name)
    : nts::AComponent(14, {1, 3, 5, 9, 11, 13}, {2, 4, 6, 8, 10, 12}, name)
{
}

nts::SixNotComponent::~SixNotComponent() = default;

nts::Tristate nts::SixNotComponent::compute(std::size_t pin)
{
    if (this->_pins.at(pin).computed)
        throw std::out_of_range("Infinite loop");

    nts::Tristate res;
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
            throw std::out_of_range("This is not an output pin");
            break;
    }
    this->_pins.at(pin).computed = true;
    this->_pins.at(pin).state = res;
    return res;
}
