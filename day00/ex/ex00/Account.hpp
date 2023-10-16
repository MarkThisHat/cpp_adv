/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:18:26 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/16 17:44:42 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

# include <iostream>
# include <vector>

class Account
{
	private:
		int	m_id;
		int	m_value;

	public:
		Account(int	id, int value);
		~Account(void);

		int 	getId(void) const;
		int 	getValue(void) const;

		void	deposit(int amount);
		void	withdraw(int amount);

		friend std::ostream& operator << (std::ostream& os, const Account& account);
};

std::ostream& operator<<(std::ostream& os, const Account& account);

#endif