/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** OrComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts {

class OrComponent : public AComponent
{
   public:
    OrComponent(const std::string &name);
    ~OrComponent();

    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
};

}  // namespace nts
