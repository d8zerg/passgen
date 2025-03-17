#pragma once

#include "basic_password_generator.h"


class UpperLetterGenerator : public BasicPasswordGenerator
{
public:
    explicit UpperLetterGenerator(size_t const length) noexcept
    : BasicPasswordGenerator(length) {}

    virtual std::string AllowedChars() const override
    {
        return "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
};

class LowerLetterGenerator : public BasicPasswordGenerator
{
public:
    explicit LowerLetterGenerator(size_t const length) noexcept
    : BasicPasswordGenerator(length) {}

    virtual std::string AllowedChars() const override
    {
        return "abcdefghijklmnopqrstuvwxyz";
    }
};