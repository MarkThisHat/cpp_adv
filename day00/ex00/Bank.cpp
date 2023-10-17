/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:45:38 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/17 07:48:41 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bank.hpp"

Bank::Bank(void) :
	liquidity(0)
{}

Bank::~Bank(void)
{
	for(Account* account: clientAccounts)
	{
		delete account;
	}
}

Account*	Bank::createAccount(int value)
{
	if (value < 0)
	{
		std::cerr << "Can't create account with negative value." << std::endl;
		return (NULL);
	}
	int id = clientAccounts.size();
	Account* newAccount = new Account(id, value);
	clientAccounts.push_back(newAccount);
	return (newAccount);
}

void	Bank::deleteAccount(int id)
{
	if (invalidId(id) || isClosed(id))
		return ;
	clientAccounts[id]->m_id *= -1;
}

void	Bank::deposit(int id, int value)
{
	if (invalidId(id) || isClosed(id))
		return ;
	if (value > 0)
	{
		int amount = static_cast<int>(value * 0.95)
		clientAccounts[id]->m_value += amount;
		liquidity += value;
	}
	else
		std::cerr << "Invalid deposit amount" << std::endl;
}

void	Bank::withdraw(int id, int value)
{
	if (invalidId(id))
		return ;
	if (value > 0)
	{
		if (value > getBalance(id))
			std::cerr << "Insufficient funds" << std::endl;
		else
		{
			clientAccounts[id]->m_value -= value;
			liquidity -= value;
		}
	}
	else
		std::cerr << "Invalid withdraw amount" << std::endl;
}

void	loan(int id, int loaned_amount)
{
	if (invalidId(id) || isClosed(id))
		return ;
	if (loaned_amount > 0 && loaned_amount > liquidity)
	{
		deposit(id, loaned_amount);
		liquidity -= loaned_amount;
	}
	else
		std::cerr << "Cannot loan that amount" << std::endl;
}

int	getLiqudity(void) const
{
	return (liquidity);
}

int	getBalance(int id) const
{
	if (invalidId(id))
		return (-1);
	return (clientAccounts[id]->m_value);
}

bool	Bank::invalidId(int id) const
{
	if (id < 0 || id >= clientAccounts.size())
	{
		std::cerr << "Invalid account ID" << std::endl;
		return (true);
	}
	return (false);
}

bool	Bank::isClosed(int id) const
{
	if (clientAccounts[id]->getId() < 0)
	{
		std::cerr << "Account ID is closed" << std::endl;
		return (true);
	}
	return (false);	
}
