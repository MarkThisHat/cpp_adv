/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:53:58 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/18 22:28:10 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
# define WORKER_HPP

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
		Shovel*		shovel;

	public:
		Worker(void);
		Worker(Shovel* oneShovel);
		~Worker(void)

		bool	pickShovel(Shovel* oneShovel);
		bool	dropShovel(void);
};

#endif