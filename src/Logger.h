#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <fstream>
#include <string>

class Logger
{
public:
	Logger();
	~Logger();
	static void warning(std::string message);
	static void note(std::string message);
	static void error(std::string message);
	
private:
	static std::ofstream* fileOut;
};

#endif // LOGGER_H
