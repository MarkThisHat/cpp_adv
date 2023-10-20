/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:29:24 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/20 13:55:06 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shovel.hpp"

Shovel::Shovel() :
Tool (SHOVEL)
{}

Shovel::Shovel(int uses) :
Tool (SHOVEL, uses)
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
