/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wheel.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:26:26 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/23 15:27:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHEEL_HPP
# define WHEEL_HPP

class	Wheel
{
	public:
		Wheel();
		~Wheel();
		virtual void	executeRotation(float p_force) = 0;
}

#endif