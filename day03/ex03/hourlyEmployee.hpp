/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hourlyEmployee.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:35:16 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/24 22:33:22 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOURLYEMPLOYEE_HPP
# define HOURLYEMPLOYEE_HPP

class TempWorker : public Employee
{
	int	registeredHours;
	int	mobilisedHours;

	public:
		TempWorker(int hourly) :
		Employee(hourly),
		registeredHours(0),
		mobilisedHours(0)
		{}

		void registerWorkHours(int hours)
		{
			registeredHours += hours;
		}

		void mobiliseForPeriod(int hours)
		{
			mobilisedHours += hours;
		}

		int executeWorkday() 
		{
			if (mobilisedHours > 0)
			{
				mobilisedHours--;
				registeredHours--;
				return hourlyValue;
			}
			if (registeredHours > 0)
			{
				registeredHours--;
				return hourlyValue;
			}
			return 0;
		}
};

#endif
