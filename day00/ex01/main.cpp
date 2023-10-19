/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:00:12 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/19 10:04:22 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graph.hpp"
#include <iostream>

int	main(void)
{
	try 
	{
		Vector2	boundries(7, 7);

		Graph graph(boundries);

		graph.addPoint(Vector2(0, 0));
		graph.addPoint(Vector2(2, 2));
		graph.addPoint(Vector2(4, 2));
		graph.addPoint(Vector2(6, 3));
		graph.addPoint(Vector2(2, 4));
		graph.addPoint(Vector2(4, 7));
		graph.addPoint(Vector2(8, 7));

		graph.display();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
