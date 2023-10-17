/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:24:47 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/17 11:12:25 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int id, int value) :
	id_(id),
	value_(value)
{}

Account::~Account(void) {};

int	Account::getId(void) const
{
	return (id_);
}

int	Account::getValue(void) const
{
	return (value_);
}

std::ostream& operator<<(std::ostream& p_os, const Account& p_account)
{
	p_os << "[" << p_account.id_ << "] - [" << p_account.value_ << "]";
	return (p_os);
}
