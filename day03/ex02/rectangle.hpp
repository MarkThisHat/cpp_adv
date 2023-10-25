/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:25:36 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/24 21:21:09 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECTANGLE_HPP
# define RECTANGLE_HPP

# include "shape.hpp"

class Rectangle : public Shape
{
	private:
		double	width_;
		double	height_;

	public:
		Rectangle(double width, double height) : 
		width_(width), 
		height_(height)
		{}

		double	getArea() const
		{
			return (width_ * height_);
		}

		double	getPerimeter() const
		{
			return (2 * (width_ + height_));
		}
};

#endif
