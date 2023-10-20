/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:53:58 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/20 14:37:41 by maalexan         ###   ########.fr       */
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

		void addWorkshop(Workshop* workshop);

	public:
		Worker(void);
		Worker(Tool* tool1);
		Worker(Tool* tool1, Tool* tool2);
		~Worker(void);

		void	releaseTool(Tool* tool);
		bool	isRegisteredTo(const Workshop* workshop) const;
		void	registerToWorkshop(Workshop* workshop);
		Tool*	getTool(ToolType type) const;
};

#endif
