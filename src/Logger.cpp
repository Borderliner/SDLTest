#include "Logger.h"

std::ofstream* Logger::fileOut = new std::ofstream("Logger.log", std::ios::out | std::ios::app);

Logger::Logger()
{
	
}

Logger::~Logger()
{

}

void Logger::warning(std::string message)
{
	std::cout<<"WARNING -> "<<message<<std::endl;
	fileOut.open("Logger.log", std::ios::out | std::ios::app);
	*fileOut<<"WARNING -> "<<message<<std::endl;
	fileOut->close();
}

void Logger::note(std::string message)
{
	std::cout<<"Note -> "<<message<<std::endl;
	fileOut->open("Logger.log", std::ios::out | std::ios::app);
	*fileOut<<"Note -> "<<message<<std::endl;
	fileOut->close();
}

void Logger::error(std::string message)
{
	std::cout<<"ERROR -> "<<message<<std::endl;
	fileOut->open("Logger.log", std::ios::out | std::ios::app);
	*fileOut<<"ERROR -> "<<message<<std::endl;
	fileOut->close();
}