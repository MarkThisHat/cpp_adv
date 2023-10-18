/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:04:01 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/18 16:39:07 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
	Bank bank;
	Account* accountA;
	Account* accountB;
	Account* accountC;
	const Account* copyAccA;

	try
	{
		accountA = bank.createAccount(-100);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\nError: " << e.what() << std::endl;
	}

	accountA = bank.createAccount(100);
	accountB = bank.createAccount(100);
	accountC = bank.createAccount(100);

	bank.deposit(accountA->getId(), 999);
	bank.deposit(accountA->getId(), 400);
	bank.deleteAccount(accountC->getId());
	bank.withdraw(accountC->getId(), 95);
	bank.loan(accountB->getId(), 1000);

	std::cout << "\nGet Account: " << std::endl;
	try
	{
		copyAccA = &bank.getById(7);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	copyAccA = &bank.getById(0);
	std::cout << "Original: " << *accountA << std::endl;
	std::cout << "\"Getted\": " << *copyAccA << std::endl;
	bank.deposit(accountA->getId(), 10);
	std::cout << "Original: " << *accountA << std::endl;
	std::cout << "\"Getted\": " << *copyAccA << std::endl;
	bank.deposit(copyAccA->getId(), 13);
	std::cout << "Original: " << *accountA << std::endl;
	std::cout << "\"Getted\": " << *copyAccA << std::endl;
	std::cout << "End Get Account\n" << std::endl;
	try
	{
		bank.deposit(accountC->getId(), -99);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
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
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try
	{
		bank.withdraw(accountC->getId(), -100);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try
	{
		bank.withdraw(accountC->getId(), 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try
	{
		bank.loan(accountB->getId(), 2000);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n" << std::endl;
	}

	std::cout << "Account: " << std::endl;
	std::cout << *accountA << std::endl;
	std::cout << *accountB << std::endl;
	std::cout << *accountC << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "\nBank: " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}
