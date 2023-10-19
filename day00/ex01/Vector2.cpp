/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:58:30 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/19 10:01:23 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2.hpp"
#include <stdexcept>

Vector2::Vector2(float x, float y)
{
	if (x < 0 || y < 0)
		throw std::invalid_argument("Coordinates cannot be negative");
	this->x = x;
	this->y = y;
}
