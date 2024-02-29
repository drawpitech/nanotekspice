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

#include "Exceptions.hpp"
#include "Factory.hpp"

nts::Parser::Parser(std::string file) : _file(std::move(file)) {}

nts::Parser::~Parser() = default;

std::unique_ptr<nts::Circuit> nts::Parser::getCircuit()
{
    auto circuit = std::make_unique<Circuit>();
    std::ifstream file(_file);

    _empty = true;
    if (!file.is_open())
        throw nts::Exception("File not found");

    std::string line;
    while (getline(file, line))
        parseLine(line, *circuit.get());
    file.close();

    if (_empty)
        throw nts::Exception("Empty file");

    return circuit;
}

void nts::Parser::parseLine(const std::string &line, Circuit &circuit)
{
    if (line.empty() ||
        std::regex_search(line, std::regex{R"(^\s*$|^\s*#.*$)"}))
        return;

    size_t i = line.find('#');
    if (i != std::string::npos) {
        parseLine(line.substr(0, i), circuit);
        return;
    }

    // Line is a section
    std::smatch matches;
    if (std::regex_search(
            line, matches, std::regex{R"(^\s*\.(\w+):(\s+)?$)"})) {
        std::string section =
            matches[1].str().empty() ? matches[0].str() : matches[1].str();
        if (!lineType.contains(section))
            throw nts::Exception("Section not found");
        _section = lineType.at(section);
        return;
    }

    if (_section == UNDEFINED)
        throw nts::Exception("Should be a section");

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
    if (!std::regex_search(
            line, matches, std::regex{R"(^\s*(\w+)\s+(\w+)(\s+)?$)"}))
        throw nts::Exception("Invalid chipset line");
    _empty = false;

    const std::string chipset = matches[1];
    const std::string name = matches[2];

    auto comp = Factory::createComponent(chipset, name);
    if (comp == nullptr)
        throw nts::Exception("Chipset not found");
    circuit.AddComponent(std::move(comp));
}

void nts::Parser::addLink(const std::string &line, Circuit &circuit)
{
    // Validate link line with regex
    // example:
    //     in_1:1 and_gate:1
    std::smatch matches;
    if (!std::regex_search(
            line, matches,
            std::regex{R"(^\s*(\w+):(\d+)\s+(\w+):(\d+)(\s+)?$)"}))
        throw nts::Exception("Invalid chipset line");

    std::string name_comp1 = matches[1];
    size_t pin1 = std::stoi(matches[2]);
    std::string name_comp2 = matches[3];
    size_t pin2 = std::stoi(matches[4]);

    IComponent &comp1 = circuit.getComponent(name_comp1);
    IComponent &comp2 = circuit.getComponent(name_comp2);

    comp1.setLink(pin1, comp2, pin2);
    comp2.setLink(pin2, comp1, pin1);
}
