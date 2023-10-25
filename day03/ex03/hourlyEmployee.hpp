/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hourlyEmployee.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:35:16 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/25 11:26:01 by maalexan         ###   ########.fr       */
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

		int		executeWorkday();
		void	mobilize(int hours);
};

#endif
