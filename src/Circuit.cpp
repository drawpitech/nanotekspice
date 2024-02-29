/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** Circuit
*/

#include "Circuit.hpp"

#include <cstddef>
#include <iostream>
#include <string>

#include "AComponent.hpp"
#include "Exceptions.hpp"
#include "tekspice.hpp"

nts::Circuit::Circuit() : _nb_components(0), _tick(0) {}

nts::Circuit::~Circuit() = default;

void nts::Circuit::AddComponent(std::unique_ptr<IComponent> newComponent)
{
    if (_components.find(newComponent->getName()) != _components.end())
        throw nts::Exception(
            "Same componenet refered two times in the circuit");
    this->_components.insert(
        {newComponent->getName(), std::move(newComponent)});
}

nts::IComponent &nts::Circuit::getComponent(const std::string &name)
{
    IComponent *res = nullptr;
    try {
        res = this->_components.at(name).get();
    } catch (const std::out_of_range &e) {
        throw nts::Exception("elt: '" + name + "' not found in components");
    }
    return *(res);
}

void nts::Circuit::simulate(std::size_t ticks)
{
    for (auto &[_, component] : _components) {
        component->simulate(1);
    }
    for (auto &[_, component] : _components) {
        if (component->getType() != nts::Type::Output)
            continue;
        component->compute(2);
    }
    if (ticks != 0)
        _tick += 1;
    this->re_init();
}

void nts::Circuit::dump()
{
    std::cout << "tick: " << _tick << "\n"
              << "input(s):\n";

    for (auto &[name, component] : _components) {
        if (component->getType() == nts::Type::Input)
            std::cout << "  " << name << ": "
                      << TRISTATE_TO_CHAR.at(component->getPinValue(1)) << "\n";
    }
    std::cout << "output(s):\n";
    for (auto &[name, component] : _components) {
        if (component->getType() == nts::Type::Output)
            std::cout << "  " << name << ": "
                      << TRISTATE_TO_CHAR.at(component->getPinValue(2)) << "\n";
    }
}

void nts::Circuit::re_init()
{
    for (auto &[_, component] : _components) {
        component->reset_pins();
    }
}
