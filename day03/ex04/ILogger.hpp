/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILogger.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:56:47 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/25 11:57:06 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILOGGER_HPP
# define ILOGGER_HPP

class	ILogger
{
	public:
		virtual ~ILogger() {}
		virtual void write(const char* message) = 0;
};

#endif
