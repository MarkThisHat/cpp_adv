/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:29:24 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/20 12:25:01 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shovel.hpp"

Shovel::Shovel() :
numberOfUses(DEFAULT_USES),
porter(NULL),
type(SHOVEL)
{}

Shovel::Shovel(int uses) :
numberOfUses(uses),
porter(NULL),
type(SHOVEL)
{}

int	Shovel::use(void)
{
	if (porter == NULL)
		return (UNCARRIED);
	if (numberOfUses)
		return (numberOfUses--);
	else
		return (BROKEN);
}
