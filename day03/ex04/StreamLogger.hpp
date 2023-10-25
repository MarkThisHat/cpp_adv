/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamLogger.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:04:20 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/25 14:13:19 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STREAMLOGGER_HPP
# define STREAMLOGGER_HPP

# include "ILogger.hpp"

class StreamLogger : public ILogger
{
	private:
		std::ostream&	outputStream;
		const char*		header;
		bool			hasTimestamp;

	public:
		StreamLogger(std::ostream& stream, const char* header = "",\
		 bool hasTimestamp = false);

		void write(const char* message);
};

#endif
