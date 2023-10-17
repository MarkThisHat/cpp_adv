/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:04:01 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/17 10:42:57 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
	Bank bank;

	Account* accountA = bank.createAccount(100);
	Account* accountB = bank.createAccount(100);

	bank.deposit(accountA->getId(), 999); 
	bank.deposit(accountA->getId(), 400); 

	std::cout << "Account : " << std::endl;
	std::cout << *accountA << std::endl;
	std::cout << *accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return 0;
}
