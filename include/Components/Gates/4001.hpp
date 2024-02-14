/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** FourNor
*/

#pragma once

#include "AComponent.hpp"

namespace nts {

class FourNorComponent : public AComponent
{
   public:
    FourNorComponent(const std::string &name);
    ~FourNorComponent();

    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
};

}  // namespace nts
