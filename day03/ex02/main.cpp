/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:27:31 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/24 21:28:28 by maalexan         ###   ########.fr       */
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

	std::cout << "Rectangle: \nArea: " << shapes[0]->getArea() << std::endl;
	std::cout << "Perimeter: " << shapes[0]->getPerimeter() << std::endl;
	std::cout << "\nTriangle: \nArea: " << shapes[1]->getArea() << std::endl;
	std::cout << "Perimeter: " << shapes[1]->getPerimeter() << std::endl;
	std::cout << "\nCircle: \nArea: " << shapes[2]->getArea() << std::endl;
	std::cout << "Perimeter: " << shapes[2]->getPerimeter() << std::endl;

	for (size_t i = 0; i < 3; i++)
		delete shapes[i];
	
	return 0;
}

/*
c++ -Wall -Werror -Wextra -I ./ main.cpp -o lid

#include <vector>

	std::vector<Shape*> shapes;
	shapes.push_back(new Rectangle(10, 5));
	shapes.push_back(new Triangle(3));
	shapes.push_back(new Circle(5));
*/
