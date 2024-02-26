/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** C4512Component
*/

#include "Components/Advanced/4512.hpp"

#include <cstddef>
#include <string>

#include "AComponent.hpp"
#include "Exceptions.hpp"
#include "tekspice.hpp"

nts::C4512Component::C4512Component(const std::string &name)
    : nts::AComponent(
          15, {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 15}, {14}, name)
{
}

nts::C4512Component::~C4512Component() = default;

nts::Tristate nts::C4512Component::getRes()
{
    nts::Tristate A = updatePin(11);
    nts::Tristate B = updatePin(12);
    nts::Tristate C = updatePin(13);

    if (updatePin(15) != nts::Tristate::False)
        return nts::Tristate::Undefined;
    if (updatePin(10) == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    if (_pins.at(10).state == nts::Tristate::True)
        return nts::Tristate::False;

    size_t selector = (A == nts::Tristate::True ? 1 : 0) +
                      ((B == nts::Tristate::True ? 1 : 0) << 1) +
                      ((C == nts::Tristate::True ? 1 : 0) << 2) + 1;

    if (selector == 8)
        selector += 1;
    return updatePin(selector);
}
nts::Tristate nts::C4512Component::compute(std::size_t pin)
{
    if (this->_pins.at(pin).value_set)
        return this->_pins.at(pin).state;
    if (this->_pins.at(pin).computed)
        throw nts::Exception("Infinite loop");

    this->_pins.at(pin).computed = true;
    nts::Tristate res = getRes();
    this->_pins.at(pin).value_set = true;
    this->_pins.at(pin).state = res;
    return res;
}
