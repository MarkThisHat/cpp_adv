/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:18:26 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/16 20:47:23 by maalexan         ###   ########.fr       */
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

		Account(int	id, int value);

		friend class Bank;

	public:
		~Account(void);

		int 	getId(void) const;
		int 	getValue(void) const;

};

#endif