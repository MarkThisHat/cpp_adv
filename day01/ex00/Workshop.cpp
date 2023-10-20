/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:30:17 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/20 12:08:15 by maalexan         ###   ########.fr       */
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

void	Workshop::releaseWorker(Worker* worker)
{
	std::vector<Worker*>::iterator it =\
	 std::find(registeredWorkers.begin(), registeredWorkers.end(), worker);
	if (it != registeredWorkers.end())
		registeredWorkers.erase(it);
	else
		throw std::runtime_error("Worker not registered in this workshop");
}

void Workshop::registerWorker(Worker* worker)
{
	for (std::vector<ToolType>::iterator it = requiredToolTypes.begin();
		it != requiredToolTypes.end(); ++it) {
		if (!worker->hasTool(*it)) {
			return;  // Worker doesn't have all required tools
		}
	}
	registeredWorkers.push_back(worker);
	worker->registerWorkshop(this);
}
