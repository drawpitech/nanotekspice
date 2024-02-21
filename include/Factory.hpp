/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** Factory
*/

#pragma once

#include <functional>
#include <map>

#include "Components/Advanced/4512.hpp"
#include "Components/Advanced/4514.hpp"
#include "Components/Elementary/AndComponent.hpp"
#include "Components/Elementary/NandComponent.hpp"
#include "Components/Elementary/NorComponent.hpp"
#include "Components/Elementary/NotComponent.hpp"
#include "Components/Elementary/OrComponent.hpp"
#include "Components/Elementary/XorComponent.hpp"
#include "Components/Gates/4001.hpp"
#include "Components/Gates/4011.hpp"
#include "Components/Gates/4030.hpp"
#include "Components/Gates/4069.hpp"
#include "Components/Gates/4071.hpp"
#include "Components/Gates/4081.hpp"
#include "Components/Specials/Clock.hpp"
#include "Components/Specials/False.hpp"
#include "Components/Specials/Input.hpp"
#include "Components/Specials/Output.hpp"
#include "Components/Specials/True.hpp"
#include "tekspice.hpp"

namespace nts {
class Factory
{
   public:
    static IComponent *createComponent(
        const std::string &type, const std::string &name);
};

using FactoryLambda = std::function<IComponent *(const std::string &)>;

// Macro to create a lambda function for the factory map
#define CREATE_COMPONENT(type)                 \
    (FactoryLambda)[](const std::string &name) \
    {                                          \
        return new type##Component(name);      \
    }

static const std::map<std::string, FactoryLambda> FACTORY_MAP = {
    // Special components
    {"clock", CREATE_COMPONENT(Clock)},
    {"false", CREATE_COMPONENT(False)},
    {"input", CREATE_COMPONENT(Input)},
    {"output", CREATE_COMPONENT(Output)},
    {"true", CREATE_COMPONENT(True)},

    // Logic gates
    {"4001", CREATE_COMPONENT(FourNor)},
    {"4011", CREATE_COMPONENT(FourNand)},
    {"4030", CREATE_COMPONENT(FourXor)},
    {"4069", CREATE_COMPONENT(SixNot)},
    {"4071", CREATE_COMPONENT(FourOr)},
    {"4081", CREATE_COMPONENT(FourAnd)},

    // Elementary components
    {"and", CREATE_COMPONENT(And)},
    {"nand", CREATE_COMPONENT(Nand)},
    {"nor", CREATE_COMPONENT(Nor)},
    {"not", CREATE_COMPONENT(Not)},
    {"or", CREATE_COMPONENT(Or)},
    {"xor", CREATE_COMPONENT(Xor)},

    // Advanced components
    {"4514", CREATE_COMPONENT(C4514)},
    {"4512", CREATE_COMPONENT(C4512)},
};
}  // namespace nts
