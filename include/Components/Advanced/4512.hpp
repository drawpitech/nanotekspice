/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** C4512
*/

#pragma once

#include <cstddef>

#include "AComponent.hpp"

namespace nts {

class C4512Component : public AComponent
{
   public:
    C4512Component(const std::string &name);
    ~C4512Component();

    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
    nts::Tristate getRes();
};

}  // namespace nts
