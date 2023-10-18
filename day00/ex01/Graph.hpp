/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:47:35 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/18 14:58:43 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_HPP
# define GRAPH_HPP

# include <vector>
# include "Vector2.hpp"

class Graph 
{
	private:
		Vector2	size_;
		std::vector<Vector2>	points_;

		bool pointExists(int x, int y) const;
		void drawRow(int y) const;
		void drawFooter() const;
	
	public:
		Graph(const Vector2& size) : 
		size_(size)
		{}
		~Graph(void) {}

	void addPoint(const Vector2& point);
	void display() const;
};

#endif
