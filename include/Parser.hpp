/*
** EPITECH PROJECT, 2024
** tekspice
** File description:
** Factory
*/

#pragma once

#include <map>
#include <string>

#include "Circuit.hpp"

namespace nts {
class Parser
{
   public:
    Parser(std::string file);
    ~Parser();

    std::unique_ptr<Circuit> getCircuit();

    enum LineType
    {
        CHIPSET,
        LINK,
        UNDEFINED,
    };

   private:
    std::string _file;
    LineType _section = UNDEFINED;

    void parseLine(const std::string &line, Circuit &circuit);

    void addChipset(const std::string &line, Circuit &circuit);
    void addLink(const std::string &line, Circuit &circuit);
};

static const std::map<std::string, nts::Parser::LineType> lineType = {
    {"chipsets", nts::Parser::CHIPSET},
    {"links", nts::Parser::LINK},
};
}  // namespace nts
