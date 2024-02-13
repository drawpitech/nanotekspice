/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** NandComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts {

class NandComponent : public AComponent
{
   public:
    NandComponent(const std::string &name);
    ~NandComponent();

    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
};

}  // namespace nts
