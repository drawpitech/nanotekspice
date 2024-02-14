/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** FourAnd
*/

#pragma once

#include "AComponent.hpp"

namespace nts {

class FourAndComponent : public AComponent
{
   public:
    FourAndComponent(const std::string &name);
    ~FourAndComponent();

    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
};

}  // namespace nts
