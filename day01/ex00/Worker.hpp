/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:53:58 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/20 16:57:24 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
# define WORKER_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>

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

		std::vector<Tool*>		tools;
		std::vector<Workshop*>	workshops;

		void 	addWorkshop(Workshop* ws);
		Tool*	getTemplatedTool(ToolType type) const;

		Position	getPosition();
		Statistic	getStatistic();

	public:
		Worker(void);
		Worker(Tool* tool1);
		Worker(Tool* tool1, Tool* tool2);
		~Worker(void);

		template<ToolType T>
		Tool*	getTool() const;
		void	releaseTool(Tool* tool);
		bool	isRegisteredTo(const Workshop* ws) const;
		void	registerToWorkshop(Workshop* ws);
};

#endif
