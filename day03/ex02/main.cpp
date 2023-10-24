/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:27:31 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/24 17:32:04 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

int main(void)
{
	Shape* shapes[3];
	shapes[0] = new Rectangle(10, 5);
	shapes[1] = new Triangle(3);
	shapes[2] = new Circle(5);

	std::cout << "Rectangle, Triangle and Circle:" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Area: " << shapes[i]->area() << std::endl;
		std::cout << "Perimeter: " << shapes[i]->perimeter() << std::endl;
		delete shapes[i];
	}
	return 0;
}

//c++ -Wall -Werror -Wextra -I ./ main.cpp -o lid
