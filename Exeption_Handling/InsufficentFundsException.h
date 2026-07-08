#pragma once

#include <exception>

class InsufficentFundsException : public std::exception
{
public:
	InsufficentFundsException() noexcept = default;
	~InsufficentFundsException() = default;
	virtual const char* what() const noexcept {
		return "Illegal Balance Exception, after withdraw youre balance must be positive or be qual to 0";
	}
};