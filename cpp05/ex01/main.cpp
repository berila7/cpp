#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Test 1: Create Valid Form ===" << std::endl;
    try {
        Form taxForm("Tax Form", 50, 25);
        std::cout << taxForm << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Form Grade Too High ===" << std::endl;
    try {
        Form badForm("Bad Form", 0, 50);
    }
    catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Form Grade Too Low ===" << std::endl;
    try {
        Form badForm("Bad Form", 50, 200);
    }
    catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Bureaucrat Can Sign ===" << std::endl;
    try {
        Form form("Parking Permit", 100, 50);
        Bureaucrat bob("Bob", 50);
        
        std::cout << "Before: " << form << std::endl;
        bob.signForm(form);
        std::cout << "After: " << form << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Bureaucrat Cannot Sign ===" << std::endl;
    try {
        Form securityForm("Security Clearance", 10, 5);
        Bureaucrat charlie("Charlie", 50);
        
        std::cout << "Before: " << securityForm << std::endl;
        charlie.signForm(securityForm);  // Should fail!
        std::cout << "After: " << securityForm << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Sign Already Signed Form ===" << std::endl;
    try {
        Form permit("Permit", 100, 50);
        Bureaucrat alice("Alice", 50);
        Bureaucrat dave("Dave", 60);
        
        alice.signForm(permit);
        dave.signForm(permit);  // Already signed, but should still work
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}