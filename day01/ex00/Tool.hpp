/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:36:43 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/23 07:27:08 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOL_HPP
# define TOOL_HPP

#include "Worker.hpp"

enum	ToolStatus
{
	DEFAULT_USES = 42,
	UNCARRIED = -1,
	BROKEN = -2
};

class	Tool
{
	protected:
		int			numberOfUses;
		Worker*		porter;
		ToolType	type;

	public:
		virtual	~Tool();
		virtual int	use() = 0;
		virtual int	getId() const = 0;
		virtual void	setPorter(Worker* worker) = 0;

		Tool(ToolType t);
		Tool(ToolType t, int uses);

		Worker*		getPorter() const;
		ToolType	getType() const;
};

#endif
