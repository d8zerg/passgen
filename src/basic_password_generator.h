#pragma once

#include <stdexcept>
#include "password_generator.h"


class BasicPasswordGenerator : public PasswordGenerator 
{
public:
    explicit BasicPasswordGenerator(size_t const length) noexcept 
    : length_(length) {} 
    
    virtual std::string Generate() override
    {
        throw std::runtime_error("not implemented");
    }

    virtual std::string AllowedChars() const override
    {
        throw std::runtime_error("not implemented");
    }

    virtual size_t Length() const override final
    {
        return length_;
    }
    
    virtual void Add(std::unique_ptr<PasswordGenerator> generator) override
    {
        throw std::runtime_error("not implemented");
    }
private:
    size_t length_;
};