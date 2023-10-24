/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brakes.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:53:29 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/24 11:11:15 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAKES_HPP
# define BRAKES_HPP

enum BrakeForce
{
	EASE = 1000,
	REGULAR = 5000,
	SUDDEN = 10000,
	EMERGENCY = 20000
};

class Brakes 
{
	public:
		int		apply_force(int force);
		bool	apply_emergency();
};

#endif
