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
        AComponent(size_t nb_pins, std::vector<size_t> inPins, std::vector<size_t> outPins);
        ~AComponent();

        void simulate(std::size_t tick);
        nts::Tristate compute (std::size_t pin);
        void setLink (std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        // nts::Tristate getLink(std::size_t pin) const;

    protected:
        std::vector<Pin> _pins;
        size_t _nb_pins;
        size_t _tick;
    private:
    };
}
