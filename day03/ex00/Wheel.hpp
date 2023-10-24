/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wheel.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:52:49 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/24 10:55:31 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHEEL_HPP
# define WHEEL_HPP

class Wheel
{
	public:
		int		turn(int angle);
		bool	straighten();
};

#endif