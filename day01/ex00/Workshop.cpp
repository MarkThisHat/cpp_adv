/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:30:17 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/21 11:46:40 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Workshop.hpp"

Workshop::Workshop()
{}

Workshop::Workshop(ToolType type1)
{
	requiredToolTypes.push_back(type1);
}

Workshop::Workshop(ToolType type1, ToolType type2)
{
	requiredToolTypes.push_back(type1);
	requiredToolTypes.push_back(type2);
}

Workshop::~Workshop()
{
	for(std::vector<Worker*>::iterator it = registeredWorkers.begin();\
	 it != registeredWorkers.end(); ++it)
	{
		std::vector<Workshop*>& workerWorkshops = (*it)->getWorkshops();
		workerWorkshops.erase(std::remove(workerWorkshops.begin(),\
		 workerWorkshops.end(), this), workerWorkshops.end());
	}
	registeredWorkers.clear();
}

void Workshop::releaseWorker(Worker* worker)
{
	std::vector<Worker*>::iterator it = \
	std::find(registeredWorkers.begin(), registeredWorkers.end(), worker);
	if (it != registeredWorkers.end())
	{
		std::vector<Workshop*>& workerWorkshops = worker->getWorkshops();
		workerWorkshops.erase(std::remove(workerWorkshops.begin(),\
		 workerWorkshops.end(), this), workerWorkshops.end());
		registeredWorkers.erase(it);
	}
	else
		throw std::runtime_error("Worker not registered in this workshop");
}

void Workshop::registerWorker(Worker* worker)
{
	if (worker->isRegisteredTo(this))
		return;
	for (std::vector<ToolType>::iterator it =\
	 requiredToolTypes.begin(); it != requiredToolTypes.end(); it++)
	{
		ToolType type = *it;
		Tool* tool = NULL;
		switch(type)
		{
			case SHOVEL:
				tool = worker->getTool<SHOVEL>();
				break;
			case HAMMER:
				tool = worker->getTool<HAMMER>();
				break;
		}
		if (tool == NULL)
			throw std::runtime_error("Worker lacks required tools.");
	}
	this->addWorker(worker);
	worker->registerToWorkshop(this);
}

void Workshop::addWorker(Worker* worker)
{
	registeredWorkers.push_back(worker);
}
