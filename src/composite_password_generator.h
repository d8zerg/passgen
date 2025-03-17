#pragma once

#include <algorithm>
#include <array>
#include <vector>
#include <random>
#include <stdexcept>
#include <utility>
#include "password_generator.h"


class CompositePasswordGenerator : public PasswordGenerator 
{
public:
    CompositePasswordGenerator() 
    {
        auto seedData = std::array<int, std::mt19937::state_size> {};
        std::generate(std::begin(seedData), std::end(seedData), std::ref(rd_));
        std::seed_seq seq(std::begin(seedData), std::end(seedData));
        engine_.seed(seq);
    }

    virtual std::string Generate() override
    {
        std::string password;
        for(auto & generator : generators_)
        {
            std::string chars = generator->AllowedChars();
            std::uniform_int_distribution<> ud(0, static_cast<int>(chars.length() - 1));

            for(size_t i = 0;i < generator->Length(); ++i)
            {
                password += chars[ud(engine_)];
            }
        }
        std::shuffle(std::begin(password), std::end(password), engine_);
        return password;
    }

    virtual void Add(std::unique_ptr<PasswordGenerator> generator) override
    {
        generators_.push_back(std::move(generator));
    }
private:
    virtual std::string AllowedChars() const override
    {
        throw std::runtime_error("not implemented");
    }

    virtual size_t Length() const override final
    {
        throw std::runtime_error("not implemented");
    }

    std::random_device rd_;
    std::mt19937 engine_;
    std::vector<std::unique_ptr<PasswordGenerator>> generators_;
};