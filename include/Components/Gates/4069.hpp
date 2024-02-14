/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** SixNot
*/

#pragma once

#include "AComponent.hpp"

namespace nts {

class SixNotComponent : public AComponent
{
   public:
    SixNotComponent(const std::string &name);
    ~SixNotComponent();

    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
};

}  // namespace nts
