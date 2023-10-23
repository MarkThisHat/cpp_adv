/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:29:24 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/23 10:39:11 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shovel.hpp"

int Shovel::nextId = 1;

Shovel::Shovel() :
Tool (SHOVEL)
{
	id = nextId++;
}

Shovel::Shovel(int uses) :
Tool (SHOVEL, uses)
{
	id = nextId++;
}

Shovel::~Shovel()
{
	if (porter)
	{
		porter->releaseTool(this);
		porter = NULL;
	}
}

int	Shovel::use(void)
{
	if (porter == NULL)
		return (UNCARRIED);
	if (numberOfUses)
	{
		std::cout << "Shovel was used, " << --numberOfUses << " left\n";
		return (numberOfUses);
	}
	else
		return (BROKEN);
}

void	Shovel::setPorter(Worker* worker)
{
	if (worker == NULL)
		porter = NULL;
	if (getPorter() == worker)
		return ;
	if (porter != NULL)
	{
		std::cout << "Worker " << porter->getLevel();
		std::cout << "'s shovel " << getId() << " was taken" << std::endl;
		porter->releaseTool(this);
	}
	porter = worker;
	if (!worker->hasTool(this))
		worker->addTool(this);
	std::cout << "Worker " << worker->getLevel() << " picked up ";
	std::cout << "shovel " << getId() << std::endl;
}

int	Shovel::getId() const
{
	return id;
}
