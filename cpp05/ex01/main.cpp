#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main()
{
	try
	{
		Bureaucrat first("moha", 194);
		std::cout << "Valid grade" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << "\n";
	}
}