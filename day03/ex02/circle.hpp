/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:41:08 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/24 21:20:58 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLE_HPP
# define CIRCLE_HPP

#include "shape.hpp"

class	Circle : public Shape
{
	private:
		double	radius;
		const double PI = 3.14159265;

	public:
		Circle(double r) :
		radius(r)
		{}

		double getArea() const
		{
			return (PI * radius * radius);
		}

		double getPerimeter() const
		{
			return (2 * PI * radius);
		}
};

#endif
