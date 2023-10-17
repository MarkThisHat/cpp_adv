/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:54:12 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/17 07:57:47 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BANK_HPP
# define BANK_HPP

# include <iostream>
# include <vector>
# include "Account.hpp"

class Bank
{
	private:
		int		liquidity;
		bool	invalidId(int id) const;
		bool	isClosed(int id) const;
		std::vector<Account *> clientAccounts;

	public:
		Bank(void);
		~Bank(void);

		Account*	createAccount(int value);
		void		deleteAccount(int id);

		void		deposit(int id, int value);
		void		withdraw(int id, int value);

		void		loan(int id, int loaned_amount);

		int			getLiqudity(void) const;
		int			getBalance(int id) const;

		friend	std::ostream& operator<<(std::ostream& p_os, const Account& p_account);

		friend	std::ostream& operator<<(std::ostream& os, const Bank& bank);
};

#endif
