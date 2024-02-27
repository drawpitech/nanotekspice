/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** 4017
*/

#pragma once

#include <cstddef>

#include "AComponent.hpp"

namespace nts {

class C4017Component : public AComponent
{
   public:
    C4017Component(const std::string &name);
    ~C4017Component();

    void simulate(std::size_t tick) final;
    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
    nts::Tristate _prev_c0;
    nts::Tristate _prev_c1;
    size_t _counter;
    void setValue();
};

}  // namespace nts
