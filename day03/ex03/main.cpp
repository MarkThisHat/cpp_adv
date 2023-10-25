/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:36:21 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/25 11:42:31 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <iostream>

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

/* ContractEmployee */
void	ContractEmployee::registerAbsentHours(int hours)
{
	absentHours += hours;
}

int	ContractEmployee::executeWorkday()
{
	if (absentHours <= 0)
		return (hourlyValue * SINGLE_DAY);
	if (absentHours >= SINGLE_DAY)
	{
		absentHours -= SINGLE_DAY;
		return (0);
	}
	int	actualWorkedHours = absentHours;
	absentHours = 0;
	return (hourlyValue * actualWorkedHours);
}

/*Apprentice*/
void	Apprentice::registerAbsentHours(int hours)
{
	absentHours += hours;
}

void	Apprentice::registerSchoolHours(int hours)
{
	schoolHours += hours;
}

int		Apprentice::executeWorkday()
{
	int	paidWorkerHours = 0;
	int	hoursCounted = 0;

	if (schoolHours > 0) 
	{
		if (schoolHours >= SINGLE_DAY)
		{
			schoolHours -= SINGLE_DAY;
			return ((hourlyValue * SINGLE_DAY) / 2);
		}
		paidWorkerHours += ((hourlyValue * schoolHours) / 2);
		hoursCounted += schoolHours;
		schoolHours = 0;
	}
	if (absentHours >= (SINGLE_DAY - hoursCounted))
	{
		absentHours -= (SINGLE_DAY - hoursCounted);
		return paidWorkerHours;
	}
	else if (absentHours > 0)
	{
		hoursCounted += absentHours;
		absentHours = 0; 
	}
	paidWorkerHours += hourlyValue * (SINGLE_DAY - hoursCounted);
	return paidWorkerHours;
}

/*TempWorker*/
void	TempWorker::mobilize(int hours)
{
	mobilizedHours += hours;
}

int		TempWorker::executeWorkday()
{
	if (mobilizedHours <= 0)
		return (0);
	if (mobilizedHours >= SINGLE_DAY)
	{
		mobilizedHours -= SINGLE_DAY;
		return (hourlyValue * SINGLE_DAY);
	}
	int	actualWorkedHours = mobilizedHours;
	mobilizedHours = 0;
	return (hourlyValue * actualWorkedHours);
}

/*EmployeeManager*/
EmployeeManager::EmployeeManager()
{
	employees = new std::vector<Employee*>();
}

EmployeeManager::~EmployeeManager()
{
	delete static_cast<std::vector<Employee*>*>(employees);
}

void	EmployeeManager::addEmployee(Employee* e)
{
	std::vector<Employee*>* empVector =\
	 static_cast<std::vector<Employee*>*>(employees);

    empVector->push_back(e);
}

void	EmployeeManager::removeEmployee(Employee* e)
{
	std::vector<Employee*>* empVector =\
	 static_cast<std::vector<Employee*>*>(employees);

	empVector->erase(std::remove(empVector->begin(),\
		empVector->end(), e), empVector->end());
}

void	EmployeeManager::executeWorkday()
{
	std::vector<Employee*>* empVector =\
	 static_cast<std::vector<Employee*>*>(employees);

	for (std::vector<Employee*>::iterator it =\
		empVector->begin(); it != empVector->end(); ++it)
		(*it)->executeWorkday();
}

void	EmployeeManager::calculatePayroll()
{
	int	totalPayRoll = 0;
	int	employeeCount = 1;

	std::vector<Employee*>* empVector =\
	 static_cast<std::vector<Employee*>*>(employees);
	for (std::vector<Employee*>::iterator it = empVector->begin();\
		it != empVector->end(); ++it)
		{
		int	salary = 0;
		for (int i = 0; i < MONTHLY_WORK; i++)
			salary += (*it)->executeWorkday();
		std::cout << "\nEmployee " << employeeCount++;
		std::cout << "\nSalary this month $" << salary << std::endl;
		totalPayRoll += salary;
		}
		std::cout << "\nPayroll of the month $" << totalPayRoll << std::endl;
}
