/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:40:23 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/22 18:20:22 by maalexan         ###   ########.fr       */
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
porter(NULL),
type(t)
{}

Tool::~Tool()
{
	if (porter)
		porter->releaseTool(this);
}

void	Tool::setPorter(Worker* worker)
{
	if (getPorter() == worker)
		return ;
	if (porter != NULL)
		porter->releaseTool(this);
	porter = worker;
	if (porter != NULL)
        porter->addTool(this);
}

Worker* Tool::getPorter() const
{
	return porter;
}

ToolType	Tool::getType() const
{
	return type;
}
