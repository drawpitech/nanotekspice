/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** AndComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts {

class AndComponent : public AComponent
{
   public:
    AndComponent(const std::string &name);
    ~AndComponent();

    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
};

}  // namespace nts
