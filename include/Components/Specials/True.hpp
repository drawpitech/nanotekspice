/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** TrueComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts {

class TrueComponent : public AComponent
{
   public:
    TrueComponent(const std::string &name);
    ~TrueComponent();

    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
};

}  // namespace nts
