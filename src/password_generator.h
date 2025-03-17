#pragma once

#include <string>
#include <memory>


class PasswordGenerator
{
public:
    virtual std::string Generate () = 0;
    virtual std::string AllowedChars() const = 0;
    virtual size_t Length() const = 0;
    virtual void Add(std::unique_ptr<PasswordGenerator> generator) = 0;
    virtual ~PasswordGenerator(){}
};