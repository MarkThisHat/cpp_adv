/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:13:59 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/24 15:40:55 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "thuesdayDiscount.hpp"
#include "packageReductionDiscount.hpp"

int main(void)
{
	int	articles1[] = { 0, 4, 6 };
	int	articles2[] = { 0, 2, 4 };
	int	articles3[] = { 6, 1, 3, 4 };

	std::cout << "Regular Order Total Price:\n";
	Command regularOrder(1, MONDAY, 101, articles1, 3);
	std::cout << regularOrder.get_total_price() << std::endl;

	std::cout << "\nTuesday Order Total Price:\n";
	ThuesdayDiscountCommand tuesdayOrder(2, TUESDAY, 102, articles2, 3);
	Command tuesdayOrderControl(3, TUESDAY, 102, articles2, 3);
	std::cout << tuesdayOrderControl.get_total_price() << std::endl;
	std::cout << tuesdayOrder.get_total_price() << std::endl;

	std::cout << "\nPackage Reduction Order Total Price:\n";
	PackageReductionDiscountCommand packageReductionOrder(4, FRIDAY, 103, articles3, 4);
	Command packageReductionOrderControl(5, FRIDAY, 103, articles3, 4);
	std::cout << packageReductionOrderControl.get_total_price() << std::endl;
	std::cout << packageReductionOrder.get_total_price() << std::endl;

	return (0);
}

//c++ -Wall -Werror -Wextra -I ./ main.cpp -o olid