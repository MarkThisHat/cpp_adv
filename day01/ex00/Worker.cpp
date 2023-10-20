/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:15:22 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/20 17:51:45 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"
#include "Tool.hpp"
#include "Workshop.hpp"

Worker::Worker(void)
{}

Worker::Worker(const std::vector<Tool*>& toolsList)
{
	for (std::vector<Tool*>::const_iterator it = toolsList.begin();\
	 it != toolsList.end(); it++)
		addTool(*it);
}

Worker::~Worker(void)
{}

void	Worker::addTool(Tool* tool)
{
	if (std::find(tools.begin(), tools.end(), tool) == tools.end())
	{
		tools.push_back(tool);
		tool->setPorter(this);
	}
	else 
		throw std::runtime_error("Worker is already holding this tool");
}

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

template<>
Tool*	Worker::getTool<SHOVEL>() const
{
	return getTemplatedTool(SHOVEL);
}

template<>
Tool*	Worker::getTool<HAMMER>() const
{
	return getTemplatedTool(HAMMER);
}

Tool*	Worker::getTemplatedTool(ToolType type) const
{
	for (std::vector<Tool*>::const_iterator it =\
	 tools.begin(); it != tools.end(); ++it)
	{
		if ((*it)->getType() == type)
			return *it;
	}
	return NULL;
}

Position	Worker::getPosition()
{
	return coordonnee;
}

Statistic	Worker::getStatistic()
{
	return stat;
}
