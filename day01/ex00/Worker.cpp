/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:15:22 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/23 10:38:23 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"
#include "Tool.hpp"
#include "Workshop.hpp"

int	Worker::id = 1;

Worker::Worker()
{
	setLevel(id++);
	std::cout << "Worker " << getLevel() << " created\n";
}

Worker::Worker(const std::vector<Tool*>& toolsList)
{
	setLevel(id++);
	for (std::vector<Tool*>::const_iterator it = toolsList.begin();\
	 it != toolsList.end(); it++)
		addTool(*it);
}

Worker::~Worker()
{
	for (std::vector<Tool*>::iterator it = tools.begin(); it != tools.end();)
	{
		(*it)->setPorter(NULL);
		tools.erase(it);
		it = tools.begin();
	}
	for(std::vector<Workshop*>::iterator it = workshops.begin();\
	 it != workshops.end(); ++it)
		(*it)->releaseWorker(this);
	workshops.clear();
}

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
		ToolType type = (*it)->getType();
		(*it)->setPorter(NULL);
		std::cout << "Worker " << getLevel() << " dropped ";
		if (type == SHOVEL)
			std::cout << "shovel ";
		else if (type == HAMMER)
			std::cout <<"hammer ";
		else
			std::cout << "Unknown tool ";
		std::cout << (*it)->getId() << std::endl;
		tools.erase(it);
	}
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

bool	Worker::hasTool(Tool* tool) const
{
	return std::find(tools.begin(), tools.end(), tool) != tools.end();
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

std::vector<Workshop*>& Worker::getWorkshops()
{
	return workshops;
}

int		Worker::getLevel() const
{
	return stat.level;
}

void	Worker::setLevel(int level)
{
	stat.level = level;
}

Position	Worker::getPosition()
{
	return coordonnee;
}

Statistic	Worker::getStatistic()
{
	return stat;
}

void Worker::printTools() const 
{
	std::cout << "Worker " << getLevel() << " ";
	if (tools.empty())
	{
		std::cout << "has no tools." << std::endl;
		return;
	}
	std::cout << "is holding:\n";
    for (std::vector<Tool*>::const_iterator it = tools.begin(); it != tools.end(); it++)
	{
		if (*it)
		{
			ToolType type = (*it)->getType();
			if (type == SHOVEL)
				std::cout << "Shovel ";
			else if (type == HAMMER)
				std::cout <<"Hammer ";
			else
				std::cout << "Unknown tool ";
			std::cout << (*it)->getId() << std::endl;
		}
    }
}
