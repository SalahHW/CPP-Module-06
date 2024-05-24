/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:32:14 by sbouheni          #+#    #+#             */
/*   Updated: 2024/05/24 15:31:20 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <ostream>
# include <sstream>
# include <string>
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <cmath>

typedef enum type
{
	unknown_type,
	char_type,
	int_type,
	double_type,
	float_type,
} type;

class ScalarConverter
{
private:
	static type determineType(std::string const &);
	static void processChar(std::string const &);
	static void processInt(std::string const &);
	static void processFloat(std::string const &);
	static void processDouble(std::string const &);
	static void printConvertedOutput(std::string const &charOutput,
								  std::string const &intOutput,
								  std::string const &doubleOutput,
								  std::string const &floatOutput);
	static bool isChar(std::string const &);
	static bool isInt(std::string const &);
	static bool isFloat(std::string const &);
	static bool isDouble(std::string const &);
	static std::string charToString(int value);
	static std::string intToString(int value);
	static std::string doubleToString(double value);
	static std::string floatToString(float value);
	/*static bool isRound(float const &value);*/
	/*static bool isRound(double const &value);*/
public:
	static void convert(std::string const &);
};

#endif
