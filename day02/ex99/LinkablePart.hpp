/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkablePart.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:06:35 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/23 15:10:24 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKABLEPART_HPP
# define LINKABLEPART_HPP

class	LinkablePart
{
	protected:

	public:
		virtual void	execute(float p_pression) = 0;
};

#endif