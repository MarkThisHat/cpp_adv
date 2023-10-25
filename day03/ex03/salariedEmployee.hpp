/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   salariedEmployee.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:35:47 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/24 22:33:24 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SALARIEDEMPLOYEE_HPP
# define SALARIEDEMPLOYEE_HPP

class   ContractEmployee : public Employee
{
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

		int		executeWorkday()
		{
			if (absentHours > 0)
			{
				absentHours--;
				return 0;
			}
			return hourlyValue;
		}
};

class Apprentice : public Employee {
    int absentHours;
    int schoolHours;

public:
    Apprentice(int hourly) : Employee(hourly), absentHours(0), schoolHours(0) {}

    void registerAbsentHours(int hours) {
        absentHours += hours;
    }

    void registerSchoolHours(int hours) {
        schoolHours += hours;
    }

    int executeWorkday() {
        if (schoolHours > 0) {
            schoolHours--;
            return hourlyValue / 2;
        }
        if (absentHours > 0) {
            absentHours--;
            return 0; // Absent
        }
        return hourlyValue;
    }
};


#endif
