/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:05:46 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/25 14:30:27 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ctime>
#include <vector>
#include <fstream>
#include <iostream>
#include "FileLogger.hpp"
#include "StreamLogger.hpp"

int main()
{
	FileLogger fileLogger1("log1.txt", "FLogger: ");
	FileLogger fileLogger2("log2.txt");
	StreamLogger consoleLogger1(std::cout, "CLogger: ");
	StreamLogger consoleLogger2(std::cout, "CLogger: ", true);

	std::vector<ILogger*> loggers;
	loggers.push_back(&fileLogger1);
	loggers.push_back(&fileLogger2);
	loggers.push_back(&consoleLogger1);
	loggers.push_back(&consoleLogger2);

	const char* messages[] = { "Message A", "Message B", "Message C" };

	for (size_t i = 0; i < sizeof(messages) / sizeof(messages[0]); i++)
	{
		for (size_t j = 0; j < loggers.size(); j++)
			loggers[j]->write(messages[i]);
	}

	return (0);
}

/*
c++ -Wall -Werror -Wextra -I ./ main.cpp -o d
*/

/* StreamLogger */
StreamLogger::StreamLogger(\
std::ostream& stream,\
 const char* header,\
  bool hasTimestamp) : 
outputStream(stream),
header(header),
hasTimestamp(hasTimestamp)
{}

void	StreamLogger::write(const char* message)
{
	if (hasTimestamp)
	{
		time_t		rawtime;
		struct tm*	timeinfo;
		char		timestamp[25];

		time(&rawtime);
		timeinfo = localtime(&rawtime);
		size_t len = strftime(timestamp, sizeof(timestamp) - 1,\
		 "%Y-%m-%d %H:%M:%S ", timeinfo);
		timestamp[len] = '\0';
		outputStream << timestamp;
	}
	if (header)
		outputStream << header;
	outputStream << message << std::endl;
}

/*FileLogger*/
FileLogger::FileLogger(\
const char* filename,\
 const char* header,\
 bool hasTimestamp) :
filename(filename),
header(header),
hasTimestamp(hasTimestamp)
{}

void	FileLogger::write(const char* message)
{
	std::fstream file(filename, std::ios::app);
	if (!file.is_open())
		return ;
	if (hasTimestamp)
	{
		time_t rawtime;
		struct tm* timeinfo;
		char timestamp[25];

		time(&rawtime);
		timeinfo = localtime(&rawtime);
		size_t len = strftime(timestamp, sizeof(timestamp) - 1,\
		 "%Y-%m-%d %H:%M:%S", timeinfo);
		timestamp[len] = '\0';
		file << timestamp;
	}
	if (header)
		file << header;
	file << message << "\n";
	file.close();
}
