/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:51:49 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/19 15:20:15 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graph.hpp"
#include <iostream>

Graph::Graph(const Vector2& size) : 
size_(size)
{}

void	Graph::addPoint(const Vector2& point)
{
	points_.push_back(point);
}

bool	Graph::pointExists(int x, int y) const
{
	for (std::vector<Vector2>::const_iterator it = points_.begin();\
	 it != points_.end(); ++it)
	{
		if (static_cast<int>(it->x) == x && static_cast<int>(it->y) == y)
			return (true);
	}
	return (false);
}

void	Graph::drawRow(int y) const
{
	std::cout << ' ' << y << ' ';
	for (int x = 0; x <= static_cast<int>(size_.x); x++)
	{
		if (pointExists(x, y))
			std::cout << 'X' << ' ';
		else
			std::cout << '.' << ' ';
	}
	std::cout << '\n';
}

void	Graph::drawFooter() const
{
	std::cout << "   ";
	for (int x = 0; x <= static_cast<int>(size_.x); x++)
		std::cout << x << ' ';
	std::cout << '\n';
}

void	Graph::display() const
{
	int y = static_cast<int>(size_.y);

	while (y >= 0)
		drawRow(y--);
	drawFooter();
}
