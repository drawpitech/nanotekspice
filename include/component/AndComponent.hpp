/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** AndComponent
*/

#pragma once
#include "AComponent.hpp"

namespace nts
{
    class AndComponent : public AComponent{
    public:
        AndComponent() = default;
        ~AndComponent() = default;

        // void simulate(std::size_t tick) {};
        nts::Tristate compute(std::size_t pin);

    protected:
    private:
    };
} // namespace nts
