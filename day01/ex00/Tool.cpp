/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:40:23 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/20 14:47:37 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tool.hpp"
#include <cstring>

Tool::Tool(ToolType t) :
numberOfUses(DEFAULT_USES),
porter(NULL),
type(t)
{}

Tool::Tool(ToolType t, int uses) :
numberOfUses(uses),
porter(NULL)
type(t)
{}

Tool::~Tool()
{}

void	Tool::setPorter(Worker* worker)
{
	if (getPorter() == worker)
		return ;
	if (porter != NULL)
		porter->releaseTool(this);
	porter = worker;
}

Worker* Tool::getPorter() const
{
	return porter;
}

ToolType	Tool::getType() const
{
	return type;
}
