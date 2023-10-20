/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:15:22 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/20 14:52:13 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"

Worker::Worker(void)
{}

Worker::Worker(Tool* tool1)
{
	tools.push_back(tool1);
	tool1->setPorter(this);
}

Worker::Worker(Tool* tool1, Tool* tool2)
{
	tools.push_back(tool1);
	tool1->setPorter(this);
	tools.push_back(tool2);
	tool2->setPorter(this);
}

Worker::~Worker(void)
{}

void	Worker::releaseTool(Tool* tool)
{
	std::vector<Tool*>::iterator it =\
	 std::find(tools.begin(), tools.end(), tool);
	if (it != tools.end())
	{
		(*it)->setPorter(NULL);
		tools.erase(it);
	}
	else
		throw std::runtime_error("Tool not in worker's possession");
}

Tool*	Worker::getTool(ToolType type) const
{
	for (std::vector<Tool*>::const_iterator it =\
	 tools.begin(); it != tools.end(); ++it)
	{
		if ((*it)->getType() == type)
			return *it;
	}
	return NULL;
}

bool	Worker::isRegisteredTo(const Workshop* workshop) const
{
	return std::find(workshop.begin(), workshop.end(), ws) != workshop.end();
}

void	Worker::registerToWorkshop(Workshop* workshop)
{
	if (this->isRegisteredTo(workshop))
		return;
	this->addWorkshop(workshop);
	workshop->registerWorker(this);
}

void	Worker::addWorkshop(Workshop* workshop)
{
	workshops.push_back(workshop);
}
