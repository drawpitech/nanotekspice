/*
** EPITECH PROJECT, 2024
** tekspice
** File description:
** Factory
*/

#include "Parser.hpp"

#include <fstream>
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
    if (std::regex_search(line, std::regex{R"(^\.(\w+):$)"})) {
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
    std::smatch matches;
    if (!std::regex_search(line, matches, std::regex{R"(^(\w+)\s+(\w+)$)"}))
        throw std::invalid_argument("Invalid chipset line");

    const std::string chipset = matches[1];
    const std::string name = matches[2];

    IComponent *comp = Factory::createComponent(chipset, name);
    if (comp == nullptr)
        throw std::invalid_argument("Chipset not found");
    circuit.AddComponent(comp);
}

void nts::Parser::addLink(const std::string &line, Circuit &circuit)
{
    // Validate link line with regex
    // example:
    //     in_1:1 and_gate:1
    std::smatch matches;
    if (!std::regex_search(
            line, matches, std::regex{R"(^(\w+):(\d+)\s+(\w+):(\d+)$)"}))
        throw std::invalid_argument("Invalid chipset line");

    std::string name_comp1 = matches[1];
    size_t pin1 = std::stoi(matches[2]);
    std::string name_comp2 = matches[3];
    size_t pin2 = std::stoi(matches[4]);

    IComponent &comp1 = circuit.getComponent(name_comp1);
    IComponent &comp2 = circuit.getComponent(name_comp2);

    comp1.setLink(pin1, comp2, pin2);
    comp2.setLink(pin2, comp1, pin1);
}
