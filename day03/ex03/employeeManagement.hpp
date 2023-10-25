/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   employeeManagement.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:34:53 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/25 11:28:34 by maalexan         ###   ########.fr       */
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
		void	addEmployee(Employee* e);
		void	removeEmployee(Employee* e);
		void	executeWorkday();
		void	calculatePayroll();
};

#endif
