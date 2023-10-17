/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:04:01 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/17 13:26:50 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
	Bank bank;
	Account* accountA;
	Account* accountB;
	Account* accountC;

	try
	{
		accountA = bank.createAccount(-100);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	accountA = bank.createAccount(100);
	accountB = bank.createAccount(100);
	accountC = bank.createAccount(100);

	bank.deposit(accountA->getId(), 999);
	bank.deposit(accountA->getId(), 400);
	try
	{
		bank.deposit(accountC->getId(), -99);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	bank.deleteAccount(accountC->getId());
	try
	{
		bank.deposit(accountC->getId() + 1, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try
	{
		bank.deposit(accountC->getId(), 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n" << std::endl;
	}
	std::cout << "Account: " << std::endl;
	std::cout << *accountA << std::endl;
	std::cout << *accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "\nBank: " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}
