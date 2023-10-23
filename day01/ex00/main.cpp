/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:10:36 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/23 12:28:17 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Workshop.hpp"


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
	hammer2.setPorter(&workerB);
	workerA.printTools();
	workerB.printTools();
	workerC.printTools();
	workerA.work();
	workerB.work();
	workerC.work();
	Workshop workshopNoTool;
	Workshop workshopOneTool(HAMMER);
	Workshop workshopBothTool(HAMMER, SHOVEL);
	workshopNoTool.executeWorkDay();
	workshopOneTool.executeWorkDay();
	workshopBothTool.executeWorkDay();
	workshopNoTool.registerWorker(&workerA);
	workshopNoTool.registerWorker(&workerB);
	workshopNoTool.registerWorker(&workerC);
	try 
	{
		workshopOneTool.registerWorker(&workerA);
		workerB.registerToWorkshop(&workshopOneTool);
		workshopOneTool.registerWorker(&workerC);	
	}
	catch(const std::exception& e)
	{
		std::cerr << "\nError: " << e.what() << std::endl;
	}
	try 
	{
		workshopBothTool.registerWorker(&workerC);
		workshopBothTool.registerWorker(&workerA);
		workshopBothTool.registerWorker(&workerB);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\nError: " << e.what() << std::endl;
	}
	workerA.work();
	workerB.work();
	workerC.work();
	workshopNoTool.executeWorkDay();
	workshopOneTool.executeWorkDay();
	workshopBothTool.executeWorkDay();
}
