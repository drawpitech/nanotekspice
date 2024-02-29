/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** Factory
*/

#pragma once

#include <functional>
#include <map>
#include <memory>

#include "Components/Advanced/4008.hpp"
#include "Components/Advanced/4013.hpp"
#include "Components/Advanced/4017.hpp"
#include "Components/Advanced/4040.hpp"
#include "Components/Advanced/4094.hpp"
#include "Components/Advanced/4512.hpp"
#include "Components/Advanced/4514.hpp"
#include "Components/Advanced/logger.hpp"
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
    static std::unique_ptr<IComponent> createComponent(
        const std::string &type, const std::string &name);

    template <typename T>
    static std::unique_ptr<IComponent> create(const std::string &name)
    {
        return std::make_unique<T>(name);
    }
};

// Macro to create a lambda function for the factory map
static const std::map<
    std::string,
    std::function<std::unique_ptr<IComponent>(const std::string &)>>
    FACTORY_MAP = {
        // Special components
        {"clock", Factory::create<ClockComponent>},
        {"false", Factory::create<FalseComponent>},
        {"input", Factory::create<InputComponent>},
        {"output", Factory::create<OutputComponent>},
        {"true", Factory::create<TrueComponent>},

        // Logic gates
        {"4001", Factory::create<FourNorComponent>},
        {"4011", Factory::create<FourNandComponent>},
        {"4030", Factory::create<FourXorComponent>},
        {"4069", Factory::create<SixNotComponent>},
        {"4071", Factory::create<FourOrComponent>},
        {"4081", Factory::create<FourAndComponent>},

        // Elementary components
        {"and", Factory::create<AndComponent>},
        {"nand", Factory::create<NandComponent>},
        {"nor", Factory::create<NorComponent>},
        {"not", Factory::create<NotComponent>},
        {"or", Factory::create<OrComponent>},
        {"xor", Factory::create<XorComponent>},

        // Advanced components
        {"4008", Factory::create<C4008Component>},
        {"4013", Factory::create<C4013Component>},
        {"4514", Factory::create<C4514Component>},
        {"4512", Factory::create<C4512Component>},
        {"4094", Factory::create<C4094Component>},
        {"4040", Factory::create<C4040Component>},
        {"4017", Factory::create<C4017Component>},
        {"logger", Factory::create<loggerComponent>},
};
}  // namespace nts
