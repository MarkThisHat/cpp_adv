/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:38:21 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/20 11:59:00 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"
#include <vector>

class Workshop 
{
	private:
		std::vector<Worker*>	registeredWorkers;
		std::vector<ToolType>	requiredToolTypes;

	public:
		Workshop();
		Workshop(ToolType type1);
		Workshop(ToolType type1, ToolType type2);
		~Workshop();

		void registerWorker(Worker* worker);
		void releaseWorker(Worker* worker);
		void executeWorkDay();
		ToolType getRequiredTool() const;
};
