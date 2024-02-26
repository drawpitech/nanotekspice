/*
** EPITECH PROJECT, 2024
** tekspice
** File description:
** Exception
*/

#include "Exceptions.hpp"

#include <utility>

nts::Exception::Exception(std::string message)
    : _message(PREFIX + std::move(message)){};

const char *nts::Exception::what() const noexcept
{
    return _message.c_str();
}
