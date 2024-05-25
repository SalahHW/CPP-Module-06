/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:48:35 by sbouheni          #+#    #+#             */
/*   Updated: 2024/05/25 02:12:33 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data test;

	test.data_int = 42;
	test.data_char = 'q';
	test.data_string = "Forty Two";

	Data* data_ptr_base = &test;

	std::cout << data_ptr_base << std::endl;
	std::cout << data_ptr_base->data_string << std::endl;
	std::cout << data_ptr_base->data_int << std::endl;
	std::cout << data_ptr_base->data_char << std::endl;

	uintptr_t ptr = Serializer::serialize(data_ptr_base);

	data_ptr_base = NULL;
	
	std::cout << data_ptr_base << std::endl;

	data_ptr_base = Serializer::deserialize(ptr);

	std::cout << data_ptr_base << std::endl;
	std::cout << data_ptr_base->data_string << std::endl;
	std::cout << data_ptr_base->data_int << std::endl;
	std::cout << data_ptr_base->data_char << std::endl;
}
