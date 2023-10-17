/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:18:26 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/17 10:50:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

class Account
{
	private:
		int		id_;
		int		value_;

		Account(int	id, int value);

		friend class Bank;

		friend std::ostream& operator<<(std::ostream& os, const Account& account);

	public:
		~Account(void);

		int 	getId(void) const;
		int 	getValue(void) const;
};

#endif