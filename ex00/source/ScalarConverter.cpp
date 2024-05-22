/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:55:34 by sbouheni          #+#    #+#             */
/*   Updated: 2024/05/23 01:54:55 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>

void ScalarConverter::convert(std::string const &input)
{
	type inputType = unknown_type;

	inputType = determineType(input);
	if (inputType == char_type)
		processChar(input);
	else if (inputType == int_type)
		processInt(input);
	else if (inputType == float_type)
		processFloat(input);
	else if (inputType == double_type)
		processDouble(input);
	else
		std::cerr << "Convert can't recognize format" << std::endl;
}

type ScalarConverter::determineType(std::string const &input)
{
	if (isChar(input))
		return (char_type);
	else if (isInt(input))
		return (int_type);
	else if (isDouble(input))
		return (double_type);
	else if (isFloat(input))
		return (float_type);
	return (unknown_type);
}

void ScalarConverter::processChar(std::string const &input)
{
	std::string char_output;
	std::string int_output;
	std::string double_output;
	std::string float_output;

	if (input.length() == 1)
		char_output = input;
	else if (input.length() == 3)
		char_output = input[1];
}

void ScalarConverter::processInt(std::string const &input)
{
	std::cout << "INT PROCESS" << std::endl;
	long int value = strtol(input.c_str(), NULL, 10);
	if (errno == ERANGE || value > INT_MAX || value < INT_MIN)
	{
		std::cerr << "Value is out of int range" << std::endl;
		errno = 0;
		return;
	}
	std::cout << value << std::endl;
}

void ScalarConverter::processFloat(std::string const &input)
{
	std::cout << "FLOAT PROCESS" << std::endl;
	float value = strtof(input.c_str(), NULL);
	if (errno == ERANGE)
	{
		std::cerr << "Value is out of float range" << std::endl;
		errno = 0;
		return;
	}
	std::cout << value << std::endl;
}

void ScalarConverter::processDouble(std::string const &input)
{
	std::cout << "DOUBLE PROCESS" << std::endl;
	double value = strtod(input.c_str(), NULL);
	if (errno == ERANGE)
	{
		std::cerr << "Value cause double underflow" << std::endl;
		errno = 0;
		return;
	}

	std::cout << value << std::endl;
}

bool ScalarConverter::isChar(const std::string &str)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'' && std::isprint(str[1]))
		return (true);
	if (str.length() == 1 && std::isprint(str[0]) && !isdigit(str[0]))
		return (true);
	return (false);
}

bool ScalarConverter::isInt(const std::string &str)
{
	if (str.empty())
		return (false);
	size_t start = 0;
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	if (start && str.length() == 1)
		return (false);
	for (size_t i = start; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

bool ScalarConverter::isFloat(const std::string &str)
{
	if (str.empty())
		return (false);
	char last_char = str[str.length() - 1];
	if (last_char != 'f')
		return (false);
	std::string numeric_part = str.substr(0, str.length() - 1);
	return (isDouble(numeric_part));
}

bool ScalarConverter::isDouble(const std::string &str)
{
	bool has_point = false;
	bool has_digit = false;
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	if (str.empty())
		return (false);
	size_t start = 0;
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	if (start && str.length() == 1)
		return (false);
	if (str[start] == '.')
		return (false);
	for (size_t i = start; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			if (has_point)
				return (false);
			has_point = true;
			if (!str[i + 1])
				return (false);
		}
		else if (std::isdigit(str[i]))
			has_digit = true;
		else
			return (false);
	}
	return (has_digit && has_point);
}

void ScalarConverter::printConvertedOutput(std::string const &charOutput,
		std::string const &intOutput,
		std::string const &floatOutput,
		std::string const &doubleOutput)
{
	std::cout << "char		= '" << charOutput << "'" << std::endl;
	std::cout << "int		= " << intOutput << std::endl;
	std::cout << "float		= " << floatOutput << std::endl;
	std::cout << "double	= " << doubleOutput << std::endl;
}
