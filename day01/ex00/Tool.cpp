/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:40:23 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/18 23:03:21 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tool.hpp"

Tool::Tool() :
numberOfUses(DEFAULT_USES),
porter(nullptr)
{}

Tool::Tool(int uses) :
numberOfUses(uses),
porter(nullptr)
{}

Tool::~Tool()
{}

virtual int	Tool::use()
{
	if (!getPorter())
		return (UNCARRIED);
	if (numberOfUses)
		return (numberOfUses--);
	else
		return (BROKEN);
}

Tool::setPorter(Worker* w)
{
	if (porter != nullptr)
		youLostItBro(porter);
	porter = w;
}

Worker* getPorter() const
{
	return (porter);
}
