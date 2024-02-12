/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** AComponent
*/

#pragma once

#include <map>
#include <vector>

#include "tekspice.hpp"

namespace nts {

class AComponent : public IComponent
{
   public:
    AComponent(
        size_t nb_pins, std::vector<size_t> inPins, std::vector<size_t> outPins,
        std::string name, Type type = Other);
    ~AComponent() override;

    void simulate(std::size_t tick) override;
    nts::Tristate compute(std::size_t pin) override;
    nts::Tristate getPinValue(std::size_t pin) const final;
    void setLink(
        std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
    void dump() const override;
    std::string getName() const final;
    Type getType() const final;
    // nts::Tristate getLink(std::size_t pin) const;
    void setInput(Tristate value) override;
    void reset_pins();

   protected:
    std::vector<Pin> _pins;
    size_t _nb_pins;
    size_t _tick;
    std::string _name;
    Type _type;

   private:
};

static const std::map<Tristate, char> TRISTATE_TO_CHAR = {
    {nts::Tristate::True, '1'},
    {nts::Tristate::False, '0'},
    {nts::Tristate::Undefined, 'U'}};

}  // namespace nts
