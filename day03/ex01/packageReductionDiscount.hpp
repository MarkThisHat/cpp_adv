/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packageReductionDiscount.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:08:09 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/24 15:20:39 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PACKAGEREDUCTIONDISCOUNT_HPP
# define PACKAGEREDUCTIONDISCOUNT_HPP

#include "command.hpp"

class	PackageReductionDiscountCommand : public Command
{
	public:
		PackageReductionDiscountCommand(\
		int id, \
		int date, \
		int client, \
		int articles[], \
		int num_articles)
		: Command(id, date, client, articles, num_articles) \
		{}

	double	get_total_price()
	{
		double	base_price = Command::get_total_price();
		return (base_price > 150.0) ? base_price - 10.0 : base_price;
	}
};

#endif