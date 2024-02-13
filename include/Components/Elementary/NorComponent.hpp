/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** NorComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts {

class NorComponent : public AComponent
{
   public:
    NorComponent(const std::string &name);
    ~NorComponent();

    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
};

}  // namespace nts
