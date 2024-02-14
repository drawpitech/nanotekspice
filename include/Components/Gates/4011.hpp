/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** FourNand
*/

#pragma once

#include "AComponent.hpp"

namespace nts {

class FourNandComponent : public AComponent
{
   public:
    FourNandComponent(const std::string &name);
    ~FourNandComponent();

    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
};

}  // namespace nts
