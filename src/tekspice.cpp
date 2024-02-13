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

    std::string arg(argv[1]);
    if (arg == "--help") {
        nts::help();
        return nts::RET_VALID;
    }
    // InputComponent in_a{"in_a"};
    // ClockComponent clock{"clock"};
    // AndComponent andgate{"andgate"};
    // OutputComponent out_b{"out_b"};
    //
    // in_a.setLink(1, andgate, 1);
    // clock.setLink(1, andgate, 2);
    // andgate.setLink(1, in_a, 1);
    // andgate.setLink(2, clock, 1);
    // out_b.setLink(1, andgate, 3);
    // andgate.setLink(3, out_b, 1);
    //
    Circuit dummy;
    // dummy.AddComponent(in_a);
    // dummy.AddComponent(clock);
    // dummy.AddComponent(andgate);
    // dummy.AddComponent(out_b);

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
