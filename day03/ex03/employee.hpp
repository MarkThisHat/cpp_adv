/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   employee.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:34:27 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/25 11:11:46 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EMPLOYEE_HPP
# define EMPLOYEE_HPP

#include <vector>
#include <algorithm>
#include <iostream>

enum	DayOfWork
{
	SINGLE_DAY = 7,
	MONTHLY_WORK = 22
};

class	Employee
{
	protected:
		int	hourlyValue;

	public:
		Employee(int hourly) : hourlyValue(hourly) {}
		virtual	~Employee() {};
		virtual int executeWorkday() = 0;
};

#endif
