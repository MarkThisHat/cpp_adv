/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:36:43 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/20 12:15:07 by maalexan         ###   ########.fr       */
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
		int 		numberOfUses;
		Worker* 	porter;
		ToolType	type;

		void	changeCarrier(Worker* priorWorker);

	public:
		virtual	~Tool(void);
		virtual int	use() = 0;
		
		Tool();
		Tool(int uses);

		void		setPorter(Worker* worker);
		Worker*		getPorter() const;
		ToolType	getType() const;
};

#endif
