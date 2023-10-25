/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   employeeManagement.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:34:53 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/25 11:16:58 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EMPLOYEEMANAGEMENT_HPP
# define EMPLOYEEMANAGEMENT_HPP

#include "employee.hpp"

class	EmployeeManager
{
	private:
		std::vector<Employee*> employees;

	public:
		void	addEmployee(Employee* e)
		{
			employees.push_back(e);
		}

		void	removeEmployee(Employee* e)
		{
			employees.erase(std::remove(employees.begin(),\
			 employees.end(), e), employees.end());
		}

		void	executeWorkday()
		{
			for (std::vector<Employee*>::iterator it =\
			 employees.begin(); it != employees.end(); ++it)
				(*it)->executeWorkday();
		}

		void	calculatePayroll()
		{
			int	totalPayRoll = 0;
			int	employeeCount = 1;

			for (std::vector<Employee*>::iterator it = employees.begin();\
			 it != employees.end(); ++it)
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
};

#endif
