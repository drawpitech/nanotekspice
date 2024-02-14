/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** FourXor
*/

#pragma once

#include "AComponent.hpp"

namespace nts {

class FourXorComponent : public AComponent
{
   public:
    FourXorComponent(const std::string &name);
    ~FourXorComponent();

    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
};

}  // namespace nts
