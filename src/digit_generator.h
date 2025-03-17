#pragma once

#include "basic_password_generator.h"


class DigitGenerator : public BasicPasswordGenerator
{
public:
    explicit DigitGenerator(size_t const length) noexcept
    : BasicPasswordGenerator(length) {}

    virtual std::string AllowedChars() const override
    {
        return "0123456789";
    }
};