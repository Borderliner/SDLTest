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
	fileOut->close(); //Close any opening stream
	std::cout<<"WARNING -> "<<message<<std::endl; //Output in console
	fileOut->open("Logger.log", std::ios::out | std::ios::app);
	*fileOut<<"WARNING -> "<<message<<std::endl; //Output in Logger.log
	fileOut->close();
}

void Logger::note(std::string message)
{
	fileOut->close();
	std::cout<<"Note -> "<<message<<std::endl;
	fileOut->open("Logger.log", std::ios::out | std::ios::app);
	*fileOut<<"Note -> "<<message<<std::endl;
	fileOut->close();
}

void Logger::error(std::string message)
{
	fileOut->close();
	std::cout<<"ERROR -> "<<message<<std::endl;
	fileOut->open("Logger.log", std::ios::out | std::ios::app);
	*fileOut<<"ERROR -> "<<message<<std::endl;
	fileOut->close();
}

void Logger::stampDate()
{
	fileOut->close();
	std::time_t now = std::time(0);
	std::tm* ltm = std::localtime(&now);
	fileOut->open("Logger.log", std::ios::out | std::ios::app);
	*fileOut<<std::endl<<"-----";
	*fileOut<<1900 + ltm->tm_year; //Prints out the year
	*fileOut<<"-"<<1 + ltm->tm_mon; //Prints out the month
	*fileOut<<"-"<<ltm->tm_mday; //Prints out the day
	*fileOut<<", "<<1 + ltm->tm_hour; //Prints out the hour
	*fileOut<<":"<< 1 + ltm->tm_min; //Prints out the minute
	*fileOut<<":"<< 1 + ltm->tm_sec; //Prints out the seconds
	*fileOut<<"-----------------------------------"<<std::endl; //Insert 35 dashes
	fileOut->close();
}
