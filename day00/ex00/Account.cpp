/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:24:47 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/16 22:43:29 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int id, int value) :
	m_id(id),
	m_value(value)
{}

Account::~Account(void) = default;

int	Account::getId(void) const
{
	return (m_id);
}

int	Account::getValue(void) const
{
	return (m_value);
}

