/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:52:59 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/26 14:26:42 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	Student* student1 = new Student("Harry");
	StudentList::getInstance().add(student1);

	Staff *staff1 = new Staff("Hagrid");
	StaffList::getInstance().add(staff1);

	Course* course1 = new Course("Potions");
	CourseList::getInstance().add(course1);

	Room* room1 = new Room("Hallway");
	RoomList::getInstance().add(room1);

	delete student1;
	delete course1;
	delete staff1;
	delete room1;

	return 0;
}
