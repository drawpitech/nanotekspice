/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** FourOr
*/

#pragma once

#include "AComponent.hpp"

namespace nts {

class FourOrComponent : public AComponent
{
   public:
    FourOrComponent(const std::string &name);
    ~FourOrComponent();

    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
};

}  // namespace nts
