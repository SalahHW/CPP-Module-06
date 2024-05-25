/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:28:14 by sbouheni          #+#    #+#             */
/*   Updated: 2024/05/25 04:15:22 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base	*generate(void)
{
	Base *base_class_ptr = NULL;
	srand(time(NULL));
	int random_number = rand() % 3;

	std::cout << "Generating called" << std::endl;
	if (random_number == 0)
	{
		std::cout << "A class generated" << std::endl;
		base_class_ptr = new A;
	}
	else if (random_number == 1)
	{
		std::cout << "B class generated" << std::endl;
		base_class_ptr = new B;
	}
	else if (random_number == 2)
	{
		std::cout << "C class generated" << std::endl;
		base_class_ptr = new C;
	}
	return (base_class_ptr);
}

void identify(Base *p)
{
	std::cout << "Identify by pointer called" << std::endl;
	std::cout << "Object is of type ";
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "Unknown";
	std::cout << std::endl;
}

void identify(Base &p)
{
	std::cout << "Identify by reference called" << std::endl;
	std::cout << "Object is of type ";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A";
	}
	catch (std::exception &)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B";
		}
		catch (std::exception &)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C";
			}
			catch (std::exception &)
			{
				std::cout << "Unknown";
			}
		}
	}
	std::cout << std::endl;
}
