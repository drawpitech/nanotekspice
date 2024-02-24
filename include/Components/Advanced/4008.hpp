/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** 4008
*/

#pragma once

#include <cstddef>

#include "AComponent.hpp"

namespace nts {

class C4008Component : public AComponent
{
   public:
    C4008Component(const std::string &name);
    ~C4008Component();

    void simulate(std::size_t tick) final;
    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
    static nts::Tristate addPins(
        nts::Tristate p1, nts::Tristate p2, nts::Tristate &carry);
};

}  // namespace nts
