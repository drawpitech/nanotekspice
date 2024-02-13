/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** ClockComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts {

class ClockComponent : public AComponent
{
   public:
    ClockComponent(const std::string &name);
    ~ClockComponent();

    void simulate(std::size_t tick) final;
    nts::Tristate compute(std::size_t pin) final;
    void setInput(Tristate value) final;

   protected:
   private:
    nts::Tristate _next;
    bool _updated;
};

}  // namespace nts
