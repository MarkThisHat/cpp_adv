/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:24:47 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/16 17:58:29 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int id, int value) : m_id(id), m_value(value) {}

int	Account::getId(void) const
{
	return (m_id);
}

int	Account::getValue(void) const
{
	return (m_value);
}

void Account::deposit(int amount)
{
	m_value += static_cast<int>(amount * 0.95);
}

bool Account::withdraw(int amount)
{
	if (amount > m_id)
	{
		std::cout << "Insufficient balance" << std::endl;
		return (false);
	}
	else
	{
		m_value -= amount;
		return (true);
	}
}

std::ostream& operator<<(std::ostream& os, const Account& account)
{
    os << "[" << account.m_id << "] - [" << account.m_value << "]";
    return os;
}
