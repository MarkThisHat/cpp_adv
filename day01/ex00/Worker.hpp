/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:53:58 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/20 12:01:31 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
# define WORKER_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>

class Tool;

enum	ToolType
{
	SHOVEL,
	HAMMER
};

struct Position
{
	int	x;
	int	y;
	int	z;
};

struct Statistic
{
	int	level;
	int	exp;
};

class Worker
{
	private:
		Position	coordonnee;
		Statistic	stat;
		std::vector<Tool*>	tools;

	public:
		Worker(void);
		Worker(Tool* tool1);
		Worker(Tool* tool1, Tool* tool2);
		~Worker(void);

		void	releaseTool(Tool* tool);
		Tool*	getTool(ToolType type) const 
};

#endif
