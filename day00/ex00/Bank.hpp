/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:54:12 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/17 11:44:47 by maalexan         ###   ########.fr       */
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
		int		liquidity_;
		std::vector<Account *> clientAccounts_;

		void	checkValidId(int id) const;
		void	checkIsOpen(int id) const;

		friend	std::ostream& operator<<(std::ostream& os, const Bank& bank);

	public:
		Bank(void);
		~Bank(void);

		Account*	createAccount(int value);
		void		deleteAccount(int id);

		void		deposit(int id, int value);
		void		withdraw(int id, int value);

		void		loan(int id, int loaned_amount);

		int			getLiquidity(void) const;
		int			getBalance(int id) const;
};

#endif
