#include "Logger.h"

Logger::Logger()
{

}

Logger::~Logger()
{

}

std::ostream& Logger::warning(std::string message)
{
	std::ostream& output;
	output<<"WARNING -> "<<message<<std::endl;
	fileOut.open("./Logger.txt", std::ofstream::out | std::ofstream::app);
	fileOut<<"WARNING -> "<<message<<std::endl;
	return output;
}

std::ostream& Logger::note(std::string message)
{
	std::ostream& output;
	output<<"Note -> "<<message<<std::endl;
	fileOut.open("./Logger.txt", std::ofstream::out | std::ofstream::app);
	fileOut<<"Note -> "<<message<<std::endl;
	return output;
}

std::ostream& Logger::error(std::string message)
{
	std::ostream& output;
	output<<"ERROR -> "<<message<<std::endl;
	fileOut.open("./Logger.txt", std::ofstream::out | std::ofstream::app);
	fileOut<<"ERROR -> "<<message<<std::endl;
	return output;
}
