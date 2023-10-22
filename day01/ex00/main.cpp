/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:10:36 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/22 18:14:05 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shovel.hpp"
#include "Hammer.hpp"


int	main(void)
{
	Shovel	shovelA;
	Hammer	hammerA;

	Worker	workerA;
	Worker	workerB;
	hammerA.setPorter(&workerA);
	hammerA.setPorter(&workerB);
}
