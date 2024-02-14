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
    if (!std::regex_search(
            line, std::regex{R"(^[a-zA-Z0-9]+ [a-zA-Z0-9_-]+$)"}))
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

    // Validate link line with regex
    // example:
    //     in_1:1 and_gate:1
    if (!std::regex_search(
            line,
            std::regex{R"(^[a-zA-Z0-9-_]+:[0-9]+ [a-zA-Z0-9-_]+:[0-9]+$)"}))
        throw std::invalid_argument("Invalid chipset line");

    std::string part1 = line.substr(0, line.find(' '));
    std::string part2 = line.substr(part1.size() + 1);

    IComponent &comp1 = circuit.getComponent(part1.substr(0, part1.find(':')));
    IComponent &comp2 = circuit.getComponent(part2.substr(0, part2.find(':')));

    size_t pin1 = std::stoi(part1.substr(part1.find(':') + 1));
    size_t pin2 = std::stoi(part2.substr(part2.find(':') + 1));

    comp1.setLink(pin1, comp2, pin2);
    comp2.setLink(pin2, comp1, pin1);
}
