/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:36:21 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/25 11:03:11 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "employeeManagement.hpp"
#include "hourlyEmployee.hpp"
#include "salariedEmployee.hpp"

int main(void)
{
	EmployeeManager	manager;

	ContractEmployee*	contract = new ContractEmployee(15);
	Apprentice* 		apprentice = new Apprentice(5);
	TempWorker*			temp = new TempWorker(10);

	manager.addEmployee(temp);
	manager.addEmployee(contract);
	manager.addEmployee(apprentice);

	temp->mobilize(50);

	contract->registerAbsentHours(42);

	apprentice->registerSchoolHours(440);
	apprentice->registerAbsentHours(21);

	manager.calculatePayroll();

	delete temp;
	delete contract;
	delete apprentice;

	return 0;
}


/*
c++ -Wall -Werror -Wextra -I ./ main.cpp -o id
*/