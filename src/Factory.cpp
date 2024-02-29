/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** Factory
*/

#include "Factory.hpp"

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(
    const std::string &type, const std::string &name)
{
    return FACTORY_MAP.contains(type) ? FACTORY_MAP.at(type)(name) : nullptr;
}
