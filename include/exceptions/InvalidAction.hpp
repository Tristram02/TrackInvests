#pragma once

#include <exception>
#include <string>

namespace exceptions
{
    class InvalidAction : public std::exception
    {
    public:
        InvalidAction(const std::string& msg) : msg_{msg}
        {
        }
        
        virtual ~InvalidAction() noexcept override = default;

        virtual const char* what() const throw() override
        {
            return this->msg_.c_str();
        }

    private:
        std::string msg_;
    };
}