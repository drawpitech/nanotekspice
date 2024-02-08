/*
** EPITECH PROJECT, 2024
** tekspice
** File description:
** tekspice
*/

#pragma once

#include <string>
#include <stdexcept>

namespace nts {

    enum {
        RET_VALID = 0,
        RET_ERROR = 84,
    };

    int tekspice(int argc, char **argv);
    void help();

    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    class IComponent
    {
        public:
        virtual ~IComponent() = default;
        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute (std::size_t pin) = 0;
        virtual void setLink (std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
    };
    class Pin
    {
       public:
        enum Type {Input, Output, Undefined};
        Pin(): pin(0), type(Type::Undefined), state(Tristate::Undefined), component(nullptr) {}
        ~Pin() = default;
        size_t pin;
        Type type;
        Tristate state;
        nts::IComponent *component;
    };
} // namespace nts
