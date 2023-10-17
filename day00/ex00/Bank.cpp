/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:45:38 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/17 10:27:35 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bank.hpp"

Bank::Bank(void) :
	liquidity_(0)
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
	clientAccounts[id]->id_ *= -1;
}

void	Bank::deposit(int id, int value)
{
	if (invalidId(id) || isClosed(id))
		return ;
	if (value > 0)
	{
		int amount = static_cast<int>(value * 0.95)
		clientAccounts[id]->value_ += amount;
		liquidity_ += value;
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
			clientAccounts[id]->value_ -= value;
			liquidity_ -= value;
		}
	}
	else
		std::cerr << "Invalid withdraw amount" << std::endl;
}

void	loan(int id, int loaned_amount)
{
	if (invalidId(id) || isClosed(id))
		return ;
	if (loaned_amount > 0 && loaned_amount > liquidity_)
	{
		deposit(id, loaned_amount);
		liquidity_ -= loaned_amount;
	}
	else
		std::cerr << "Cannot loan that amount" << std::endl;
}

int	getLiqudity(void) const
{
	return (liquidity_);
}

int	getBalance(int id) const
{
	if (invalidId(id))
		return (-1);
	return (clientAccounts[id]->value_);
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

friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
{
	p_os << "[" << p_account.id_ << "] - [" << p_account.value_ << "]";
	return (p_os);
}

friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank.liquidity_ << std::endl;
	for (auto &clientAccount : p_bank.clientAccounts)
	p_os << *clientAccount << std::endl;
	return (p_os);
}
