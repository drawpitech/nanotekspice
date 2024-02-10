/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** OutputComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts {

class OutputComponent : public AComponent
{
   public:
    OutputComponent(const std::string &name);
    ~OutputComponent();

    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
    nts::Tristate _next;
};

}  // namespace nts
