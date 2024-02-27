/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** 4094
*/

#pragma once

#include <cstddef>

#include "AComponent.hpp"
#include "tekspice.hpp"

namespace nts {

class C4094Component : public AComponent
{
   public:
    C4094Component(const std::string &name);
    ~C4094Component();

    void simulate(std::size_t tick) final;
    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
    nts::Tristate _prev_clock;
    void clockUp(
        nts::Tristate enable, nts::Tristate strobe, nts::Tristate data);
    void clockDown(
        nts::Tristate enable, nts::Tristate strobe, nts::Tristate data);
    void setValuesTrue();
};

}  // namespace nts
