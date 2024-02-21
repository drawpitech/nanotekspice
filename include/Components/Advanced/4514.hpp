/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** C4514
*/

#pragma once

#include <array>
#include <cstddef>

#include "AComponent.hpp"
#include "tekspice.hpp"

namespace nts {

class C4514Component : public AComponent
{
   public:
    C4514Component(const std::string &name);
    ~C4514Component();

    void simulate(std::size_t tick) final;
    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
    std::array<nts::Tristate, 4> _previous_inputs;
    std::array<nts::Tristate, 4> _actual_inputs;
    std::array<size_t, 16> _in_to_out = {11, 9,  10, 8,  7,  6,  5,  4,
                                         18, 17, 20, 19, 14, 13, 16, 15};
    nts::Tristate _old_strobe;

    nts::Tristate getRes();
    void setAllOutputs(nts::Tristate state);
};

}  // namespace nts
