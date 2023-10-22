/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hammer.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:28:30 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/22 18:08:47 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAMMER_HPP
# define HAMMER_HPP

#include "Tool.hpp"

class Hammer : public Tool
{
	private:
		int			id;
		static int	nextId;

	public:
		Hammer();
		Hammer(int uses);
		int		getId() const;
		void	setPorter(Worker* worker);
		virtual int use();
};

#endif
