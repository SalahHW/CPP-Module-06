/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:19:59 by sbouheni          #+#    #+#             */
/*   Updated: 2024/05/25 02:46:53 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP 

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base
{
public:
	virtual	~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
