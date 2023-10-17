/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:10:54 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/16 21:02:58 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <vector>

# include "Account.hpp"
# include "Bank.hpp"

#endif

/*
void	deposit(int amount);
		void	withdraw(int amount);

		friend std::ostream& operator << (std::ostream& os, const Account& account);
};

std::ostream& operator<<(std::ostream& os, const Account& account);


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
*/