/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** XorComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts {

class XorComponent : public AComponent
{
   public:
    XorComponent(const std::string &name);
    ~XorComponent();

    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
};

}  // namespace nts
