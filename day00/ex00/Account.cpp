/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:24:47 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/17 10:19:35 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int id, int value) :
	id_(id),
	value_(value)
{}

Account::~Account(void) = default;

int	Account::getId(void) const
{
	return (id_);
}

int	Account::getValue(void) const
{
	return (value_);
}
