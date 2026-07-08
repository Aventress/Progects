#pragma once

#include <exception>

class NegativeBalanceException : public std::exception
{
public:
	NegativeBalanceException() noexcept = default;
	~NegativeBalanceException() = default;
	virtual const char* what() const noexcept {
		return "Illegal Balance Exception, balance must be positive number or equal to 0(zero)";
	}
};