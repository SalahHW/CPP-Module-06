/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:55:34 by sbouheni          #+#    #+#             */
/*   Updated: 2024/05/24 15:34:32 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
		std::cerr << "Format not recognized" << std::endl;
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
	char char_value = 0;
	int  int_value = 0;
	double double_value = 0;
	float float_value = 0;

	if (input.length() == 1)
		char_value = input[0];
	else if (input.length() == 3)
		char_value = input[1];
	int_value = static_cast<int>(char_value);
	double_value = static_cast<double>(char_value);
	float_value = static_cast<float>(char_value);
	char_output = char_value;
	int_output = intToString(int_value);
	double_output = doubleToString(double_value) + ".0";
	float_output = floatToString(float_value) + ".0f";
	printConvertedOutput(char_output, int_output, double_output, float_output);
}

void ScalarConverter::processInt(std::string const &input)
{
	std::string char_output;
	std::string int_output;
	std::string double_output;
	std::string float_output;
	double double_value = 0;
	float float_value = 0;
	int		int_value = 0;

	// Int conversion
	long long_value = strtol(input.c_str(), NULL, 10);
	if (errno == ERANGE || long_value > INT_MAX || long_value < INT_MIN)
	{
		std::cerr << "Int overflow" << std::endl;
		return ;
	}
	int_value = static_cast<int>(long_value);
	double_value = static_cast<double>(int_value);
	float_value = static_cast<float>(int_value);
	char_output = charToString(int_value);
	int_output = intToString(int_value);
	double_output = doubleToString(double_value);
	float_output = floatToString(float_value);
	printConvertedOutput(char_output, int_output, double_output, float_output);
}

void ScalarConverter::processFloat(std::string const &input)
{
	std::string char_output;
	std::string int_output;
	std::string double_output;
	std::string float_output;
	int int_value;
	double double_value;
	float float_value;
	long long_value;

	// Float conversion
	float_value = strtof(input.c_str(), NULL);
	if (errno)
	{
		std::cerr << "Float overflow" << std::endl;
		return ;
	}
	float_output = floatToString(float_value);
	// Int and Char conversion
	long_value = strtol(input.c_str(), NULL, 10);
	if (errno)
	{
		int_output = "Impossible";
		char_output = "Impossible";
		errno = 0;
	}
	else
	{
		long_value = static_cast<long>(float_value);
		if (long_value < INT_MIN || long_value > INT_MAX)
		{
			int_output = "Impossible";
			char_output = "Impossible";
		}
		else
		{
			int_value = static_cast<int>(float_value);
			int_output = intToString(int_value);
			char_output = charToString(int_value);
		}
	}
	// Double conversion
	double_value = static_cast<double>(float_value);
	double_output = doubleToString(double_value);
	printConvertedOutput(char_output, int_output, double_output, float_output);
}

void ScalarConverter::processDouble(std::string const &input)
{
	std::string char_output;
	std::string int_output;
	std::string double_output;
	std::string float_output;
	int int_value;
	double double_value;
	float float_value;
	long long_value;

	// Double conversion
	double_value = strtod(input.c_str(), NULL);
	if (errno)
	{
		std::cerr << "Float overflow" << std::endl;
		return;
	}
	double_output = doubleToString(double_value);

	// Float conversion
	float_value = strtof(input.c_str(), NULL);
	if (errno)
	{
		float_output = "Impossible";
	}
	else 
	{
		float_output = floatToString(float_value);
	}
	errno = 0;

	// Int and Char conversion
	long_value = strtol(input.c_str(), NULL, 10);
	if (errno)
	{
		int_output = "Impossible";
		char_output = "Impossible";
		errno = 0;
	}
	else
	{
		long_value = static_cast<long>(double_value);
		if (long_value < INT_MIN || long_value > INT_MAX)
		{
			int_output = "Impossible";
			char_output = "Impossible";
		}
		else
		{
			int_value = static_cast<int>(double_value);
			int_output = intToString(int_value);
			char_output = charToString(int_value);
		}
	}
	printConvertedOutput(char_output, int_output, double_output, float_output);
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

std::string ScalarConverter::charToString(int value)
{
	std::string char_output;
	char		char_value;

	if (value < 0 || value > 255)
		char_output = "Impossible";
	else
	{
		char_value = static_cast<char>(value);
		if (isprint(char_value))
			char_output = char_value;
		else
			char_output = "Non displayable";
	}
	return (char_output);
}

std::string ScalarConverter::intToString(int value)
{
	std::stringstream ss;
	ss << value;
	return (ss.str());
}

std::string ScalarConverter::doubleToString(double value)
{
	std::stringstream ss;
	ss << std::fixed << std::setprecision(1) << value;
	return (ss.str());
}

std::string ScalarConverter::floatToString(float value)
{
	std::stringstream ss;
	ss << std::fixed << std::setprecision(1) << value << "f";
	return (ss.str());
}

void ScalarConverter::printConvertedOutput(std::string const &charOutput,
		std::string const &intOutput,
		std::string const &doubleOutput,
		std::string const &floatOutput)
{
	if (charOutput == "Impossible" || charOutput == "Non displayable")
		std::cout << "char		= "<< charOutput << std::endl;
	else
		std::cout << "char		= '" << charOutput << "'" << std::endl;
	std::cout << "int		= " << intOutput << std::endl;
	std::cout << std::fixed << "float		= " << floatOutput << std::endl;
	std::cout << "double		= " << doubleOutput << std::endl;
}
