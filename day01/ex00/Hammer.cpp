/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hammer.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:29:24 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/22 18:09:43 by maalexan         ###   ########.fr       */
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

int	Hammer::use(void)
{
	if (porter == NULL)
		return (UNCARRIED);
	if (numberOfUses)
	{
		std::cout << "Hammer was used, " << --numberOfUses << " left\n";
		return (numberOfUses);
	}
	else
		return (BROKEN);
}

void	Hammer::setPorter(Worker* worker)
{
	if (getPorter() == worker)
		return ;
	if (porter != NULL)
	{
		porter->releaseTool(this);
		std::cout << "Worker " << porter->getLevel() << " released ";
		std::cout << "hammer " << getId() << std::endl;
	}
	porter = worker;
	std::cout << "Worker " << worker->getLevel() << " picked up ";
	std::cout << "hammer " << getId() << std::endl;
}

int	Hammer::getId() const
{
	return id;
}
