/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileLogger.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:03:37 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/25 14:15:37 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILELOGGER_HPP
# define FILELOGGER_HPP

# include "ILogger.hpp"

class FileLogger : public ILogger
{
	private:
		const char*	filename;
		const char*	header;
		bool		hasTimestamp;

	public:
		FileLogger(const char* filename, const char* header = "",\
		 bool hasTimestamp = false);

		void write(const char* message);
};

#endif
