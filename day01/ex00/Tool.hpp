/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:36:43 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/18 23:06:52 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOL_HPP
# define TOOL_HPP

enum	ToolStatus
{
	DEFAULT_USES = 42,		
	UNCARRIED = -1,
	BROKEN = -2
};

class	Tool
{
	protected:
		int numberOfUses;
		Worker* porter;

	public:
		virtual int use(void);
		virtual ~Tool(void);

		void setPorter(Worker* w);
		Worker* getPorter(void) const;
};
