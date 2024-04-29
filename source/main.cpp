/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:39:58 by sbouheni          #+#    #+#             */
/*   Updated: 2024/04/29 16:17:03 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    (void) argv;
    if (argc != 2)
    {
        std::cerr << "Usage: ./convert [value]" << std::endl;
        return (1);
    }
    return (0);
}