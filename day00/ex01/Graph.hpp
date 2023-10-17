/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:47:35 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/17 17:23:45 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_HPP
# define GRAPH_HPP

# include <vector>

struct Vector2
{
	float	x;
	float	y;
};

class Graph 
{
	private:
		Vector2	size_;
		std::vector<Vector2>	points_;

	public:
		Graph(const Vector2& size);
}

#endif