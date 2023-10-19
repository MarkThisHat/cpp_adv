/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:15:22 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/19 12:53:58 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"

Worker::Worker(void)
{}

Worker::Worker(Tool* tool1)
{
	tools.push_back(tool1);
}

Worker::Worker(Tool* tool1, Tool* tool2)
{
	tools.push_back(tool1);
	tools.push_back(tool2);
}

Worker::~Worker(void)
{}

void	Worker::releaseTool(Tool* tool)
{
	std::vector<Tool*>::iterator it =\
	 std::find(tools.begin(), tools.end(), tool);
	if (it != tools.end())
		tools.erase(it);
	else
		throw std::runtime_error("Tool not in worker's possession");
}
