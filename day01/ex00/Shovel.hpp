/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:28:30 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/18 22:29:11 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOVEL_HPP
# define SHOVEL_HPP

#include "Worker.hpp"

class Shovel
{
	int	numberOfUses;

	int	use(void)
	{
		if (numberOfUses)
			return (numberOfUses--);
		else
			return (-1);
	}
};

#endif