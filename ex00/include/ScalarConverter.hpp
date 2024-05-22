/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:32:14 by sbouheni          #+#    #+#             */
/*   Updated: 2024/05/23 01:49:43 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cerrno>
# include <climits>

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
		static void printConvertedOutput(std::string const &, std::string const &, std::string const &, std::string const &);
		static bool isChar(std::string const &);
		static bool isInt(std::string const &);
		static bool isFloat(std::string const &);
		static bool isDouble(std::string const &);
	public:
		static void convert(std::string const &);
};

#endif
