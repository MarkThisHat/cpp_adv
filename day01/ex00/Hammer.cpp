/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hammer.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:29:24 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/23 11:15:17 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hammer.hpp"

int Hammer::nextId = 1;

Hammer::Hammer() :
Tool (HAMMER)
{
	id = nextId++;
}

Hammer::Hammer(int uses) :
Tool (HAMMER, uses)
{
	id = nextId++;
}

Hammer::~Hammer()
{
	if (porter)
	{
		porter->releaseTool(this);
		porter = NULL;
	}
}

int	Hammer::use(void)
{
	if (porter == NULL)
		return (UNCARRIED);
	if (numberOfUses)
	{
		std::cout << "-H- Hammer was used, " << --numberOfUses << " left\n";
		return (numberOfUses);
	}
	else
		return (BROKEN);
}

void	Hammer::setPorter(Worker* worker)
{
	if (worker == NULL)
		porter = NULL;
	if (getPorter() == worker)
		return ;
	if (porter != NULL)
	{
		std::cout << "-H- Worker " << porter->getLevel();
		std::cout << "'s hammer " << getId() << " was taken" << std::endl;
		porter->releaseTool(this);
	}
	porter = worker;
	if (!worker->hasTool(this))
		worker->addTool(this);
	std::cout << "-H- Worker " << worker->getLevel() << " picked up ";
	std::cout << "hammer " << getId() << std::endl;
}

int	Hammer::getId() const
{
	return id;
}
