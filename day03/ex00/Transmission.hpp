/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Transmission.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:51:44 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/24 10:55:18 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSMISSION_HPP
# define TRANSMISSION_HPP

class Transmission 
{
	public:
		int		shift_up();
		int		shift_down();
		bool	reverse();
};

#endif