/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:30:17 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/23 12:32:33 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Workshop.hpp"

int	Workshop::nextId = 1;

Workshop::Workshop()
{
	id = nextId++;
	std::cout << "#F# Workshop " << getId() << " created\n";
}

Workshop::Workshop(ToolType type1)
{
	id = nextId++;
	std::cout << "#F# Workshop " << getId() << " created, requires: ";
	switch(type1)
	{
		case SHOVEL:
			std::cout << "shovels\n";
			break ;
		case HAMMER:
			std::cout << "hammers\n";
			break;
	}
	requiredToolTypes.push_back(type1);
}

Workshop::Workshop(ToolType type1, ToolType type2)
{
	id = nextId++;
	std::cout << "#F# Workshop " << getId() << " created, requires: ";
	switch(type1)
	{
		case SHOVEL:
			std::cout << "shovels and ";
			break ;
		case HAMMER:
			std::cout << "hammers and ";
			break;
	}
	switch(type2)
	{
		case SHOVEL:
			std::cout << "shovels\n";
			break ;
		case HAMMER:
			std::cout << "hammers\n";
			break;
	}
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
		registeredWorkers.erase(it);
		std::vector<Workshop*>& workerWorkshops = worker->getWorkshops();
		workerWorkshops.erase(std::remove(workerWorkshops.begin(),\
		 workerWorkshops.end(), this), workerWorkshops.end());
	}
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
	std::cout << "#F# Worker " << worker->getLevel() << " was registered ";
	worker->registerToWorkshop(this);
	std::cout << "to workshop " << getId() << std::endl;
}

void	Workshop::executeWorkDay()
{
	std::cout << "#F# Workshop " << getId() << " launching work day\n";
	for (std::vector<Worker*>::iterator it =\
	 registeredWorkers.begin(); it != registeredWorkers.end(); ++it)
	 {
		std::cout << "  ";
		(*it)->work(this);
	 }
	if (registeredWorkers.empty())
		std::cout << "  #F# Workshop " << getId() << " doesn't have workers\n";
	std::cout << "\t#F# Workshop " << getId() << " finished work day\n";
}

int	Workshop::getId() const
{
	return id;
}

void Workshop::addWorker(Worker* worker)
{
	registeredWorkers.push_back(worker);
}
