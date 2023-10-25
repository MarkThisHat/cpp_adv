/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   employeeManagement.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:34:53 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/25 09:41:34 by maalexan         ###   ########.fr       */
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
			int	employeeSalary;
			int	totalPayRoll = 0;
			int	employeeCount = 1;
	
			for (std::vector<Employee*>::iterator it = employees.begin();\
			 it != employees.end(); ++it)
			 {
				std::cout << "Employee " << count++ << ":\n$";
				employeeSalary = (*it)->executeWorkday() * MONTHLY_WORK;
				std::cout << " this month\n" << employeeSalary << std::endl;
				totalPayRoll += employeeSalary;
			 }
			 std::cout << "Payroll of the month $" << totalPayRoll << std::endl;
		}
};

#endif
