/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** logger
*/

#pragma once

#include <cstddef>
#include <cstdint>

#include "AComponent.hpp"
#include "tekspice.hpp"

namespace nts {

class loggerComponent : public AComponent
{
   public:
    loggerComponent(const std::string &name);
    ~loggerComponent();

    void simulate(std::size_t tick) final;
    nts::Tristate compute(std::size_t pin) final;

   protected:
   private:
    nts::Tristate _prev_c;
    uint8_t getValue();
};

}  // namespace nts
