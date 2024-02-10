/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** NotComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts {

class NotComponent : public AComponent
{
   public:
    NotComponent(const std::string &name);
    ~NotComponent();

    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
};

}  // namespace nts
