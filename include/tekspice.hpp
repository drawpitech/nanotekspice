/*
** EPITECH PROJECT, 2024
** tekspice
** File description:
** tekspice
*/

#pragma once

#include <stdexcept>
#include <string>

namespace nts {

enum
{
    RET_VALID = 0,
    RET_ERROR = 84,
};

int tekspice(int argc, char **argv);
void help();

enum Tristate
{
    Undefined = (-true),
    True = true,
    False = false
};
Tristate operator&&(Tristate left, Tristate right);
Tristate operator||(Tristate left, Tristate right);
Tristate operator!(Tristate entry);
Tristate operator^(Tristate left, Tristate right);
Tristate Nand(nts::Tristate left, nts::Tristate right);
Tristate Nor(nts::Tristate left, nts::Tristate right);

enum Type
{
    Input,
    Output,
    Other,
};

class IComponent
{
   public:
    virtual ~IComponent() = default;
    virtual void simulate(std::size_t tick) = 0;
    virtual nts::Tristate compute(std::size_t pin) = 0;
    virtual nts::Tristate updatePin(std::size_t pin) = 0;
    virtual nts::Tristate getPinValue(std::size_t pin) const = 0;
    virtual void setLink(
        std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
    virtual void dump() const = 0;
    virtual Type getType() const = 0;
    virtual std::string getName() const = 0;
    virtual void setInput(Tristate value) = 0;
    virtual void reset_pins() = 0;
};

class Pin
{
   public:
    Pin()
        : pin(0),
          type(Type::Other),
          state(Tristate::Undefined),
          component(nullptr),
          computed(false),
          value_set(false)
    {
    }
    ~Pin() = default;

    size_t pin;
    Type type;
    Tristate state;
    nts::IComponent *component;
    bool computed;
    bool value_set;
};
}  // namespace nts
