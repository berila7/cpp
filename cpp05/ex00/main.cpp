#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Test 1: Valid Bureaucrat ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;  // Test operator
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Grade Too High (0) ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 0);
		std::cout << "Should not reach here!" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Grade Too Low (151) ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 151);
		std::cout << "Should not reach here!" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Increment Grade ===" << std::endl;
	try {
		Bureaucrat dave("Dave", 2);
		std::cout << "Before: " << dave << std::endl;
		dave.incrementGrade();
		std::cout << "After increment: " << dave << std::endl;
		dave.incrementGrade();  // Should throw!
		std::cout << "Should not reach here!" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Decrement Grade ===" << std::endl;
	try {
		Bureaucrat eve("Eve", 149);
		std::cout << "Before: " << eve << std::endl;
		eve.decrementGrade();
		std::cout << "After decrement: " << eve << std::endl;
		eve.decrementGrade();  // Should throw!
		std::cout << "Should not reach here!" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Copy Constructor ===" << std::endl;
	try {
		Bureaucrat frank("Frank", 50);
		Bureaucrat frankCopy(frank);
		std::cout << "Original: " << frank << std::endl;
		std::cout << "Copy: " << frankCopy << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Assignment Operator ===" << std::endl;
	try {
		Bureaucrat george("George", 100);
		Bureaucrat helen("Helen", 50);
		std::cout << "Before assignment:" << std::endl;
		std::cout << "  George: " << george << std::endl;
		std::cout << "  Helen: " << helen << std::endl;
		
		george = helen;
		
		std::cout << "After 'george = helen':" << std::endl;
		std::cout << "  George: " << george << std::endl;
		std::cout << "  Helen: " << helen << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 8: Boundary Values ===" << std::endl;
	try {
		Bureaucrat min("Minimum", 1);
		Bureaucrat max("Maximum", 150);
		std::cout << min << std::endl;
		std::cout << max << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}