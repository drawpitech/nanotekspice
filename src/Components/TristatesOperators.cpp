/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** TristatesOperators
*/

#include "tekspice.hpp"

nts::Tristate nts::operator&&(nts::Tristate left, nts::Tristate right)
{
    switch (left) {
        case nts::Tristate::True:
            return right;
        case nts::Tristate::False:
            return nts::Tristate::False;
        case nts::Tristate::Undefined:
            if (right == nts::Tristate::False)
                return nts::Tristate::False;
            return nts::Tristate::Undefined;
        default:
            return nts::Tristate::Undefined;
    }
}

nts::Tristate nts::operator||(nts::Tristate left, nts::Tristate right)
{
    switch (left) {
        case nts::Tristate::True:
            return nts::Tristate::True;
        case nts::Tristate::False:
            return right;
        case nts::Tristate::Undefined:
            if (right == nts::Tristate::False)
                return nts::Tristate::False;
            return nts::Tristate::Undefined;
        default:
            return nts::Tristate::Undefined;
    }
}

nts::Tristate nts::operator!(nts::Tristate entry)
{
    if (entry == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    if (entry == nts::Tristate::True)
        return nts::Tristate::False;
    return nts::Tristate::True;
}

nts::Tristate nts::operator^(nts::Tristate left, nts::Tristate right)
{
    switch (left) {
        case nts::Tristate::True:
            return !right;
        case nts::Tristate::False:
            return right;
        default:
            return nts::Tristate::Undefined;
    }
}
