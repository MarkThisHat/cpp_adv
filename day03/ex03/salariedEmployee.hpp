/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   salariedEmployee.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:35:47 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/25 11:25:09 by maalexan         ###   ########.fr       */
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

		int		executeWorkday();
		void	registerAbsentHours(int hours);
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

		int		executeWorkday();
		void	registerAbsentHours(int hours);
		void	registerSchoolHours(int hours);
	};

#endif
