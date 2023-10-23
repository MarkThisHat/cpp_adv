/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:10:36 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/23 10:08:21 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shovel.hpp"
#include "Hammer.hpp"


int	main(void)
{
	Shovel	shovelA;
	Hammer	hammerA;
	std::vector<Tool*> toolsA;

	Shovel shovel1;
	Shovel shovel2;
	toolsA.push_back(&shovel1);
	toolsA.push_back(&shovel2);
	Hammer hammer1;
	Hammer hammer2;
	toolsA.push_back(&hammer1);
	toolsA.push_back(&hammer2);
	Worker	workerA;
	Worker	workerB;
	Worker	workerC(toolsA);
	workerA.printTools();
	hammerA.setPorter(&workerA);
	workerA.printTools();
	workerB.printTools();
	hammerA.setPorter(&workerB);
	hammerA.setPorter(&workerA);
	workerA.printTools();
	workerB.printTools();
	workerC.printTools();
}
