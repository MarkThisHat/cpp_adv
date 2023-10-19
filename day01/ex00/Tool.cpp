/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:40:23 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/19 11:32:17 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tool.hpp"
#include <cstring>

Tool::Tool() :
numberOfUses(DEFAULT_USES),
porter(NULL)
{}

Tool::Tool(int uses) :
numberOfUses(uses),
porter(NULL)
{}

Tool::~Tool()
{}

void	Tool::setPorter(Worker* w)
{
	if (porter != NULL)
		changeCarrier(porter);
	porter = w;
}

Worker* Tool::getPorter() const
{
	return porter;
}

void	Tool::changeCarrier(Worker* priorWorker)
{
	priorWorker->releaseTool(this);
}
