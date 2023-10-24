/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:31:24 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/24 16:41:35 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
	private:
		double	side_;
		static const double	SQRT3_DIV_4 = 0.433;

	public:
		Triangle(double side) : 
		side_(side)
		{}

		double	area() const
		{
			return (SQRT3_DIV_4 * side * side);
		}

		double	perimeter() const
		{
			return (3 * side);
		}
};

#endif 
