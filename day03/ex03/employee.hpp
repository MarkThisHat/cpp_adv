/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   employee.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:34:27 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/24 22:26:03 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EMPLOYEE_HPP
# define EMPLOYEE_HPP

#include <vector>
#include <algorithm>
#include <iostream>

enum	DayOfWork
{
	SINGLE_DAY = 7
}

class	Employee
{
	protected:
		int	hourlyValue;

	public:
		Employee(int hourly): hourlyValue(hourly) {}
		virtual int executeWorkday() = 0;
};

class	Mobilizable
{
	public:
		virtual void mobilizeForHours(int hours) = 0;
};

class	AbsentRegisterable
{
	public:
		virtual void registerAbsentHours(int hours) = 0;
};

class	SchoolAttendable
{
	public:
		virtual void registerSchoolHours(int hours) = 0;
};

#endif
