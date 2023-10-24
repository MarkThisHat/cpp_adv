/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:19:00 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/24 15:41:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Car.hpp"

int main(void)
{
	Car	deluxeCar;

	std::cout << "Starting the car:" << std::endl;
	deluxeCar.start();

	std::cout << "\nAccelerating and shifting gears:" << std::endl;
	deluxeCar.accelerate(50);
	deluxeCar.shift_gears_up();

	std::cout << "\nMaking a turn:" << std::endl;
	deluxeCar.turn_wheel(45);

	std::cout << "\nStopping the car:" << std::endl;
	deluxeCar.stop();

	std::cout << "\nEmergency situation:" << std::endl;
	deluxeCar.apply_emergency_brakes();

	return (0);
}

int		Car::accelerate(int speed)
{
	std::cout << "Accelerating to " << speed << "km/h" << std::endl;
	return (speed);
}

bool	Engine::start()
{
	std::cout << "Engine started." << std::endl;
	return (true);
}

bool	Engine::stop()
{
	std::cout << "Engine stopped." << std::endl;
	return (true);
}

int		Brakes::apply_force(int force)
{
	std::cout << "Applied " << force << "N of force on brakes." << std::endl;
	return (force);
}

bool	Brakes::apply_emergency()
{
	std::cout << "Applied emergency brakes!" << std::endl;
	return (true);
}

int		Transmission::shift_up()
{
	std::cout << "Shifted up a gear." << std::endl;
	return (1);
}

int		Transmission::shift_down()
{
	std::cout << "Shifted down a gear." << std::endl;
	return (-1);
}

bool	Transmission::reverse()
{
	std::cout << "Transmission set to reverse." << std::endl;
	return (true);
}

int		Wheel::turn(int angle)
{
	std::cout << "Turned wheel by " << angle << " degrees." << std::endl;
	return (angle);
}

bool	Wheel::straighten()
{
	std::cout << "Wheels straightened." << std::endl;
	return (true);
}

//c++ -Wall -Werror -Wextra -I ./ main.cpp -o solid