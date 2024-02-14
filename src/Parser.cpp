/*
** EPITECH PROJECT, 2024
** tekspice
** File description:
** Factory
*/

#include "Parser.hpp"

#include <fstream>
#include <iostream>
#include <memory>
#include <regex>
#include <utility>

#include "Factory.hpp"

nts::Parser::Parser(std::string file) : _file(std::move(file)) {}

nts::Parser::~Parser() = default;

std::unique_ptr<nts::Circuit> nts::Parser::getCircuit()
{
    auto circuit = std::make_unique<Circuit>();
    std::ifstream file(_file);

    if (!file.is_open())
        throw std::invalid_argument("File not found");

    std::string line;
    while (getline(file, line))
        parseLine(line, *circuit.get());
    file.close();

    return circuit;
}

void nts::Parser::parseLine(const std::string &line, Circuit &circuit)
{
    if (line.empty() || line.at(0) == '#')
        return;

    // Line is a section
    if (std::regex_search(line, std::regex{R"(^\.(\w+)\:$)"})) {
        std::string section =
            line.substr(1, line.size() - 2 - (long)line.ends_with('\n'));
        if (!lineType.contains(section))
            throw std::invalid_argument("Section not found");
        _section = lineType.at(section);
        return;
    }

    if (_section == UNDEFINED)
        throw std::invalid_argument("Should be a section");

    switch (_section) {
        case UNDEFINED:
            break;
        case CHIPSET:
            addChipset(line, circuit);
            break;
        case LINK:
            addLink(line, circuit);
            break;
    }
}

void nts::Parser::addChipset(const std::string &line, Circuit &circuit)
{
    // Validate chipset line with regex
    // example:
    //     4001 super_chip
    const std::regex r{R"(^[a-zA-Z0-9]+ [a-zA-Z0-9_-]+$)"};
    if (!std::regex_search(line, r))
        throw std::invalid_argument("Invalid chipset line");

    std::string chipset = line.substr(0, line.find(' '));
    std::string name = line.substr(line.find(' ') + 1);
    IComponent *comp = Factory::createComponent(chipset, name);
    if (comp == nullptr)
        throw std::invalid_argument("Chipset not found");
    circuit.AddComponent(comp);
}

void nts::Parser::addLink(const std::string &line, Circuit &circuit)
{
    /*
    InputComponent in_a{"in_a"};
    ClockComponent clock{"clock"};
    OrComponent Orgate{"Orgate"};
    OutputComponent out_b{"out_b"};

    in_a.setLink(1, Orgate, 1);
    clock.setLink(1, Orgate, 2);
    Orgate.setLink(1, in_a, 1);
    Orgate.setLink(2, clock, 1);
    out_b.setLink(1, Orgate, 3);
    Orgate.setLink(3, out_b, 1);

    Circuit dummy;
    dummy.AddComponent(&in_a);
    dummy.AddComponent(&clock);
    dummy.AddComponent(&Orgate);
    dummy.AddComponent(&out_b);
    */
}
