/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** FourNandComponent
*/

#include "Components/Gates/4011.hpp"

#include <cstddef>
#include <stdexcept>
#include <string>

#include "AComponent.hpp"
#include "tekspice.hpp"

nts::FourNandComponent::FourNandComponent(const std::string &name)
    : nts::AComponent(14, {1, 2, 5, 6, 8, 9, 12, 13}, {3, 4, 10, 11}, name)
{
}

nts::FourNandComponent::~FourNandComponent() = default;

nts::Tristate nts::FourNandComponent::compute(std::size_t pin)
{
    // if (pin > this->_nb_pins)
    // throw std::out_of_range("Pin is out of range");
    // if (this->_pins.at(pin).type != nts::Output)
    // return nts::Tristate::Undefined;
    if (this->_pins.at(pin).computed)
        throw std::out_of_range("Infinite loop");

    nts::Tristate res;
    switch (pin) {
        case 3:
        case 10:
            res = Nand(updatePin(pin - 1), updatePin(pin - 2));
            break;
        case 4:
        case 11:
            res = Nand(updatePin(pin + 1), updatePin(pin + 2));
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
