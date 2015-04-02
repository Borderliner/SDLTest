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
	fileOut->open("Logger.log", std::ios::out | std::ios::app);
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

void Logger::stampDate()
{
	std::time_t now = std::time(0);
	std::tm* ltm = std::localtime(&now);
	fileOut->open("Logger.log", std::ios::out | std::ios::app);
	*fileOut<<1900 + ltm->tm_year; //Prints out the year
	*fileOut<<"-"<<1 + ltm->tm_mon; //Prints out the month
	*fileOut<<"-"<<ltm->tm_mday; //Prints out the day
	*fileOut<<", "<<1 + ltm->tm_hour; //Prints out the hour
	*fileOut<<":"<< 1 + ltm->tm_min; //Prints out the minute
	*fileOut<<":"<< 1 + ltm->tm_sec; //Prints out the seconds
	*fileOut<<std::endl<<"----------------------------------------"<<std::endl; //Insert 40 dashes
	fileOut->close();
}
