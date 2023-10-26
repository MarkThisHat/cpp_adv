/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Room.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:04:01 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/25 22:46:08 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_HPP
# define ROOM_HPP

class	Room
{
	private:
		long long				ID;
		std::vector<Person*>	_occupants;

	public:
		Room();
		~Room();
		bool	canEnter(Person*);
		void	enter(Person*);
		void	exit(Person*);
		
		void	printOccupant();
};

#endif
