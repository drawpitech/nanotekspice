/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** AComponent
*/

#pragma once

#include "tekspice.hpp"
#include <vector>

namespace nts {
    class AComponent : public IComponent{
    public:
        AComponent(size_t nb_pins);
        ~AComponent() = default;

        void simulate(std::size_t tick) {};
        virtual nts::Tristate compute (std::size_t pin) = 0;
        void setLink (std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        nts::Tristate getLink(std::size_t pin) const;

    protected:
        std::vector<nts::IComponent &> _component;
        std::vector<size_t> _pin;
        size_t _nb_pins;
    private:
    };
}
