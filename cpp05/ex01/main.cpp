#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "=== good ===" << std::endl;
    try {
        Form taxForm("Tax Form", 50, 25);
        std::cout << taxForm << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== bad ===" << std::endl;
    try {
        Form badForm("Bad Form", 0, 50);
    }
    catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}