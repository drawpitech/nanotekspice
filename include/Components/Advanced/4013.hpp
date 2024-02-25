/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** 4013
*/

#pragma once

#include <array>
#include <cstddef>

#include "AComponent.hpp"

namespace nts {

class C4013Component : public AComponent
{
   public:
    C4013Component(const std::string &name);
    ~C4013Component();

    void simulate(std::size_t tick) final;
    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
    void computeFF(std::array<size_t, 6> pins);
};

}  // namespace nts
