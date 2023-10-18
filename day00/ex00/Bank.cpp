/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:45:38 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/18 10:16:26 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bank.hpp"

Bank::Bank(void) :
	liquidity_(0)
{}

Bank::~Bank(void)
{
	for (std::vector<Account*>::iterator it = clientAccounts_.begin();\
	 it != clientAccounts_.end(); ++it)
		delete *it;
}

Account*	Bank::createAccount(int value)
{
	if (value < 0)
		throw std::runtime_error("Can't create account with negative value.");
	int id = clientAccounts_.size();
	int amount = static_cast<int>(value * 0.95);
	Account* newAccount = new Account(id, amount);
	liquidity_ += value;
	clientAccounts_.push_back(newAccount);
	return (newAccount);
}

void	Bank::deleteAccount(int id)
{
	checkValidId(id);
	checkIsOpen(id);
	clientAccounts_[id]->id_ *= -1;
}

void	Bank::deposit(int id, int value)
{
	if (value <= 0)
		throw std::runtime_error("Invalid deposit amount");
	checkValidId(id);
	checkIsOpen(id);
	int amount = static_cast<int>(value * 0.95);
	clientAccounts_[id]->value_ += amount;
	liquidity_ += value;
}

void	Bank::withdraw(int id, int value)
{
	if (value <= 0)
		throw std::runtime_error("Invalid withdraw amount");
	checkValidId(id);
	if (value > getBalance(id))
		throw std::runtime_error("Insufficient funds");
	clientAccounts_[id]->value_ -= value;
	liquidity_ -= value;
}

void	Bank::loan(int id, int loaned_amount)
{
	checkValidId(id);
	checkIsOpen(id);
	if (loaned_amount <= 0 || loaned_amount > getLiquidity())
		throw std::runtime_error("Cannot loan that amount");
	deposit(id, loaned_amount);
	liquidity_ -= loaned_amount;
}

int	Bank::getLiquidity(void) const
{
	return (liquidity_);
}

int	Bank::getBalance(int id) const
{
	checkValidId(id);
	return (clientAccounts_[id]->value_);
}

int			getId(int id) const
{
	checkValidId(id);
	return (clientAccounts_[id]->id_);
}

void	Bank::checkValidId(int& id) const
{
	if (id < 0)
		id = -id;
	if (id >= (int)clientAccounts_.size())
		throw std::runtime_error("Invalid account ID");
}

void	Bank::checkIsOpen(int id) const
{
	if (clientAccounts_[id]->getId() < 0)
		throw std::runtime_error("Account ID is closed");
}

std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank)
{
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank.liquidity_ << std::endl;
	for (std::vector<Account*>::const_iterator it = p_bank.clientAccounts_.begin();\
	 it != p_bank.clientAccounts_.end(); ++it)
		if ((*it)->getId() >= 0)
			p_os << **it << std::endl;
	return (p_os);
}
