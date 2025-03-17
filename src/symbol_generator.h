#pragma once

#include "basic_password_generator.h"


class SymbolGenerator : public BasicPasswordGenerator
{
public:
    explicit SymbolGenerator(size_t const length) noexcept
    : BasicPasswordGenerator(length) {}

    virtual std::string AllowedChars() const override
    {
        return "!@#$%^&*(){}[]?<>";
    }
};