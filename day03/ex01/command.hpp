/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:12:18 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/24 14:59:29 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

enum DayOfTheWeek
{
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY
};

class	Command 
{
	protected:
		int	id;
		int	date;
		int	client;
		int	articles[7];
		int	num_articles;

		double	price_list[7] = {50.0, 75.0, 60.0, 80.0, 90.0, 410.0, 999.98};

	public:
		Command(int id, int date, int client, int articles[], int num_articles)	: 
		id(id),
		date(date),
		client(client),
		num_articles(num_articles)
		{
			for(int i = 0; i < num_articles; i++)
				this->articles[i] = articles[i];
		}

		virtual double	get_total_price()
		{
			double	total = 0.0;
			for (int i = 0; i < num_articles; i++)
				total += price_list[articles[i]];
			return total;
		}
};

#endif