/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:40:23 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/20 12:21:34 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tool.hpp"
#include <cstring>

Tool::Tool() :
numberOfUses(DEFAULT_USES),
porter(NULL),
type(0)
{}

Tool::Tool(int uses) :
numberOfUses(uses),
porter(NULL)
type(0)
{}

Tool::~Tool()
{}

void	Tool::setPorter(Worker* worker)
{
	if (getPorter() == worker)
		return ;
	if (porter != NULL)
		changeCarrier(porter);
	porter = worker;
}

Worker* Tool::getPorter() const
{
	return porter;
}

void	Tool::changeCarrier(Worker* priorWorker)
{
	priorWorker->releaseTool(this);
}

ToolType	Tool::getType() const
{
	return type;
}
