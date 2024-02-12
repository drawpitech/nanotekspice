/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** Circuit
*/

#include "Circuit.hpp"

#include <iostream>

#include "AComponent.hpp"
#include "tekspice.hpp"

nts::Circuit::Circuit() : _nb_components(0), _tick(0) {}

nts::Circuit::~Circuit() {}

void nts::Circuit::AddComponent(IComponent &newComponent, std::string name)
{
    if (_components.find(name) != _components.end())
        throw std::out_of_range(
            "Same compoenet refered two times in the circuit");
    this->_components.at(name) = &newComponent;
}

nts::IComponent &nts::Circuit::getComponent(std::string name)
{
    return *(this->_components.at(name));
}

void nts::Circuit::simulate(std::size_t /* ticks */)
{
    for (auto [_, component] : _components) {
        if (component->getType() != nts::Type::Input)
            continue;
        component->compute(1);
    }
}

void nts::Circuit::dump()
{
    std::cout << "tick: " << _tick << "\n"
              << "input(s):\n";

    for (auto [name, component] : _components) {
        if (component->getType() == nts::Type::Input)
            std::cout << "  " << name << ": "
                      << TRISTATE_TO_CHAR.at(component->getPinValue(1)) << "\n";
    }
    std::cout << "output(s):\n";
    for (auto [name, component] : _components) {
        if (component->getType() == nts::Type::Output)
            std::cout << "  " << name << ": "
                      << TRISTATE_TO_CHAR.at(component->getPinValue(2)) << "\n";
    }
}

void nts::Circuit::re_init()
{
    for (auto [_, component] : _components) {
        component->reset_pins();
    }
}
