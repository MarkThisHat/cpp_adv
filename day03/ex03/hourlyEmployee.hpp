/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hourlyEmployee.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:35:16 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/25 09:58:59 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOURLYEMPLOYEE_HPP
# define HOURLYEMPLOYEE_HPP

#include "employee.hpp"

class	TempWorker : public Employee
{
	private:
		int	mobilizedHours;

	public:
		TempWorker(int hourly) :
		Employee(hourly),
		mobilizedHours(0)
		{}

		void mobilize(int hours)
		{
			mobilizedHours += hours;
		}

		int executeWorkday()
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
};

#endif
