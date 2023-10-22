/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:53:58 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/22 17:28:09 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
# define WORKER_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <iostream>

class	Tool;
class	Workshop;

enum	ToolType
{
	SHOVEL,
	HAMMER
};

struct	Position
{
	int	x;
	int	y;
	int	z;
};

struct	Statistic
{
	int	level;
	int	exp;
};

class Worker
{
	private:
		Position	coordonnee;
		Statistic	stat;

		static int	id;
		
		std::vector<Tool*>		tools;
		std::vector<Workshop*>	workshops;

		void 	addWorkshop(Workshop* ws);
		Tool*	getTemplatedTool(ToolType type) const;

		Position	getPosition();
		Statistic	getStatistic();
		void		setLevel(int level);

	public:
		Worker(void);
		Worker(const std::vector<Tool*>& toolsList);
		~Worker(void);

		void	addTool(Tool* tool);
		void	releaseTool(Tool* tool);
		bool	isRegisteredTo(const Workshop* ws) const;
		void	registerToWorkshop(Workshop* ws);
		template<ToolType T>
		Tool*	getTool() const;
		std::vector<Workshop*>&	getWorkshops();
		int		getLevel();
};

#endif
