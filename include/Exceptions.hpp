/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-celian.lombardot
** File description:
** Factory
*/

#pragma once

#include <exception>
#include <string>

namespace nts {

#ifdef DEBUG_MODE
    #define STRINGIFY(x) #x
    #define TOSTRING(x) STRINGIFY(x)
    #define PREFIX std::string(__FILE_NAME__ ":" TOSTRING(__LINE__) ": ")
#else
    #define PREFIX std::string("")
#endif

class Exception : public std::exception
{
   public:
    Exception(std::string message);
    [[nodiscard]] const char *what() const noexcept override;

   private:
    std::string _message;
};
}  // namespace nts
