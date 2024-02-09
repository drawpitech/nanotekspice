/*
** EPITECH PROJECT, 2024
** tekspice
** File description:
** tekspice
*/

#include "tekspice.hpp"

#include <iostream>

#include "AComponent.hpp"
#include "Shell.hpp"

int nts::tekspice(int argc, char **argv)
{
    if (argv == nullptr || argc == 0)
        return nts::RET_ERROR;

    if (argc == 1) {
        std::cerr << "Not enough arguments.\nUse --help" << std::endl;
        return nts::RET_ERROR;
    }
    if (argc > 2) {
        std::cerr << "Too many arguments.\nUse --help" << std::endl;
        return nts::RET_ERROR;
    }

    std::string arg(argv[1]);
    if (arg == "--help") {
        nts::help();
        return nts::RET_VALID;
    }

    AComponent dummy(0, {}, {}, "component");
    Shell shell(&dummy);
    shell.run();
    return nts::RET_VALID;
}

void nts::help()
{
    std::cout << "USAGE\n"
                 "\t./tekspice [file.nts]\n"
                 "\n"
                 "DESCRIPTION\n"
                 "\tfile.nts\ta file describing the circuit to be simulated\n";
}
