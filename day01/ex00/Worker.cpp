/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:15:22 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/18 22:23:46 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"

Worker::Worker(void)
{}

Worker::Worker(Shovel* oneShovel) :
shovel(oneShovel)
{}

Worker::~Worker(void)
{}

bool Worker::dropShovel(void)
{
	if (shovel == nullptr)
		return (false);
	shovel = nullptr;
	return (true);
}
