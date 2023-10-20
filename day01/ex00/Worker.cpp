/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:15:22 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/20 15:14:03 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"
#include "Tool.hpp"
#include "Workshop.hpp"

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

bool	Worker::isRegisteredTo(const Workshop* ws) const
{
	return (std::find(workshops.begin(), workshops.end(), ws)\
	 != workshops.end());
}

void	Worker::registerToWorkshop(Workshop* ws)
{
	if (this->isRegisteredTo(ws))
		return;
	this->addWorkshop(ws);
	ws->registerWorker(this);
}

void	Worker::addWorkshop(Workshop* workshop)
{
	workshops.push_back(workshop);
}

Position	Worker::getPosition()
{
	return coordonnee;
}

Statistic	Worker::getStatistic()
{
	return stat;
}
