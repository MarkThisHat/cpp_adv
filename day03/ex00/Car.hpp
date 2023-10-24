/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Car.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:59 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/24 11:16:33 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAR_HPP
# define CAR_HPP

# include "Engine.hpp"
# include "Transmission.hpp"
# include "Wheel.hpp"
# include "Brakes.hpp"

class	Car
{
	private:
		Engine			engine;
		Transmission	transmission;
		Wheel			wheels;
		Brakes			brakes;

	public:
		bool	start() { engine.start(); }
		bool	stop() 
		{
			engine.stop();
			brakes.apply_force(REGULAR);
		}
		int		accelerate(int speed);
		int		shift_gears_up() { transmission.shift_up(); }
		int		shift_gears_down() { transmission.shift_down(); }
		void	reverse() { transmission.reverse(); }
		int		turn_wheel(int angle) { wheels.turn(angle); }
		void	straighten_wheels() { wheel.straighten(); }
		void	apply_force_on_brakes(int force) { brakes.apply_force(force); }
		void	apply_emergency_brakes() { brakes.apply_emergency(); }
};

#endif