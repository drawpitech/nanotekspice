/*
** EPITECH PROJECT, 2024
** tekspice
** File description:
** tekspice
*/

#include "tekspice.hpp"

#include <iostream>

#include "AComponent.hpp"
#include "Circuit.hpp"
#include "Components/Elementary/AndComponent.hpp"
#include "Components/Elementary/NotComponent.hpp"
#include "Components/Elementary/OrComponent.hpp"
#include "Components/Elementary/XorComponent.hpp"
#include "Components/Specials/Clock.hpp"
#include "Components/Specials/Input.hpp"
#include "Components/Specials/Output.hpp"
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

    const std::string arg(argv[1]);
    if (arg == "--help") {
        nts::help();
        return nts::RET_VALID;
    }
    InputComponent in_a{"in_a"};
    ClockComponent clock{"clock"};
    OrComponent Orgate{"Orgate"};
    OutputComponent out_b{"out_b"};
    //
    in_a.setLink(1, Orgate, 1);
    clock.setLink(1, Orgate, 2);
    Orgate.setLink(1, in_a, 1);
    Orgate.setLink(2, clock, 1);
    out_b.setLink(1, Orgate, 3);
    Orgate.setLink(3, out_b, 1);

    Circuit dummy;
    dummy.AddComponent(in_a);
    dummy.AddComponent(clock);
    dummy.AddComponent(Orgate);
    dummy.AddComponent(out_b);

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
