/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:39:58 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/30 00:47:11 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/ScalarConverter/ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    (void) argv;
    if (argc != 2)
    {
        std::cerr << "Usage: ./convert [value]" << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
    return (0);
}