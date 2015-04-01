#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <fstream>

class Logger
{
public:
	Logger();
	~Logger();
	static std::ostream& warning(std::string message);
	static std::ostream& note(std::string message);
	static std::ostream& error(std::string message);
	
private:
	std::ofstream fileOut("./Logger.txt");
};

#endif // LOGGER_H
