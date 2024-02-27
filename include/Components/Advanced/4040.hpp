/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** 4040
*/

#pragma once

#include <cstddef>

#include "AComponent.hpp"
#include "tekspice.hpp"

namespace nts {

class C4040Component : public AComponent
{
   public:
    C4040Component(const std::string &name);
    ~C4040Component();

    void simulate(std::size_t tick) final;
    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
    size_t _counter;
    nts::Tristate _prev_clock;
    void addCount();
};

}  // namespace nts
