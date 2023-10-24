/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thuesdayDiscount.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:40:25 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/24 15:20:32 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THUESDAY_HPP
# define THUESDAY_HPP

#include "command.hpp"

class	ThuesdayDiscountCommand : public Command
{
	public:
		ThuesdayDiscountCommand(\
		int id, \
		int date, \
		int client, \
		int articles[], \
		int num_articles)
		: Command(id, date, client, articles, num_articles) \
		{}

		double get_total_price()
		{
			double base_price = Command::get_total_price();
			return (date == TUESDAY) ? base_price * 0.9 : base_price; 
		}
};

#endif
