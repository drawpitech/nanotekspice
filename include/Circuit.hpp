/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** Circuit
*/

#pragma once

#include <cstddef>
#include <map>
#include <string>

#include "tekspice.hpp"

namespace nts {
class Circuit
{
   public:
    Circuit();
    ~Circuit();

    void AddComponent(IComponent &newComponent);
    IComponent &getComponent(const std::string &name);
    void simulate(std::size_t ticks);
    void dump();
    void re_init();

   protected:
   private:
    std::map<std::string, IComponent *> _components;
    std::size_t _nb_components;
    size_t _tick;
};
}  // namespace nts