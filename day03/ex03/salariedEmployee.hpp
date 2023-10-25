/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   salariedEmployee.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:35:47 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/25 11:10:49 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SALARIEDEMPLOYEE_HPP
# define SALARIEDEMPLOYEE_HPP

#include "employee.hpp"

class	ContractEmployee : public Employee
{
	private:
		int	absentHours;

	public:
		ContractEmployee(int hourly) :
		Employee(hourly),
		absentHours(0)
		{}

		void	registerAbsentHours(int hours)
		{
			absentHours += hours;
		}

		int executeWorkday()
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
};

class	Apprentice : public Employee
{
	private:
		int	absentHours;
		int	schoolHours;

	public:
		Apprentice(int hourly) : 
		Employee(hourly),
		absentHours(0),
		schoolHours(0)
		{}

		void registerAbsentHours(int hours)
		{
			absentHours += hours;
		}

		void registerSchoolHours(int hours)
		{
			schoolHours += hours;
		}

	int		executeWorkday()
	{
		int paidWorkerHours = 0;
		int hoursCounted = 0;

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
};

#endif
