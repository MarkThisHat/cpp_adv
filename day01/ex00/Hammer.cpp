/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hammer.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:29:24 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/20 12:25:24 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hammer.hpp"

Hammer::Hammer() :
numberOfUses(DEFAULT_USES),
porter(NULL),
type(HAMMER)
{}

Hammer::Hammer(int uses) :
numberOfUses(uses),
porter(NULL),
type(HAMMER)
{}

int	Hammer::use(void)
{
	if (porter == NULL)
		return (UNCARRIED);
	if (numberOfUses)
		return (numberOfUses--);
	else
		return (BROKEN);
}
