/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Room.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:04:01 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/25 17:04:40 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Room
{
	private:
		long long				ID;
		std::vector<Person*>	_occupants;

	public:
		Room();
		bool	canEnter(Person*);
		void	enter(Person*);
		void	exit(Person*);
		
		void	printOccupant();
};
