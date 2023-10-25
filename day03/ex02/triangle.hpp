/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:31:24 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/24 21:21:30 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
	private:
		double	side_;
		const double SQRT3_DIV_4 = 0.43333;

	public:
		Triangle(double side) : 
		side_(side)
		{}

		double	getArea() const
		{
			return (SQRT3_DIV_4 * side_ * side_);
		}

		double	getPerimeter() const
		{
			return (3 * side_);
		}
};

#endif 
