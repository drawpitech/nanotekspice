/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** Circuit
*/

#include "Circuit.hpp"

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>

#include "AComponent.hpp"
#include "tekspice.hpp"

nts::Circuit::Circuit() : _nb_components(0), _tick(0) {}

nts::Circuit::~Circuit() = default;

void nts::Circuit::AddComponent(IComponent &newComponent)
{
    if (_components.find(newComponent.getName()) != _components.end())
        throw std::out_of_range(
            "Same compoenet refered two times in the circuit");
    this->_components.insert({newComponent.getName(), &newComponent});
}

nts::IComponent &nts::Circuit::getComponent(const std::string &name)
{
    IComponent *res = nullptr;
    try {
        res = this->_components.at(name);
    } catch (const std::out_of_range &e) {
        throw std::out_of_range("elt not found in components");
    }
    return *(res);
}

void nts::Circuit::simulate(std::size_t /* ticks */)
{
    for (auto [_, component] : _components) {
        if (component->getType() != nts::Type::Output)
            continue;
        component->compute(2);
    }
    _tick += 1;
    this->re_init();
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