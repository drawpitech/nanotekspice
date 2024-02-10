/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** FalseComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts {

class FalseComponent : public AComponent
{
   public:
    FalseComponent(const std::string &name);
    ~FalseComponent();

    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
};

}  // namespace nts
