#include "Point.hpp"
#include <iostream>

int main(void)
{
    // 1. Define the Triangle Vertices
    // Triangle: (0,0) -> (20,0) -> (10,20)
    Point a(0.0f, 0.0f);
    Point b(20.0f, 0.0f);
    Point c(10.0f, 20.0f);

    // 2. Define Test Points
    Point inside(10.0f, 5.0f);   // inside
    Point outside(30.0f, 30.0f); // outside
    Point vertex(0.0f, 0.0f);    // Exactly on a vertex (A)
    Point edge(10.0f, 0.0f);     // Exactly on an edge (between A and B)

    // 3. Run Tests
    std::cout << "Triangle: A(0,0), B(20,0), C(10,20)" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    // Test 1: Inside
    if (bsp(a, b, c, inside) == true)
        std::cout << "1. Inside Point (10, 5): \033[32mPASS\033[0m (Returned True)" << std::endl;
    else
        std::cout << "1. Inside Point (10, 5): \033[31mFAIL\033[0m (Returned False)" << std::endl;

    // Test 2: Outside
    if (bsp(a, b, c, outside) == false)
        std::cout << "2. Outside Point (30,30): \033[32mPASS\033[0m (Returned False)" << std::endl;
    else
        std::cout << "2. Outside Point (30,30): \033[31mFAIL\033[0m (Returned True)" << std::endl;

    // Test 3: Vertex (Should be False)
    if (bsp(a, b, c, vertex) == false)
        std::cout << "3. Vertex Point (0,0):   \033[32mPASS\033[0m (Returned False)" << std::endl;
    else
        std::cout << "3. Vertex Point (0,0):   \033[31mFAIL\033[0m (Returned True)" << std::endl;

    // Test 4: Edge (Should be False)
    if (bsp(a, b, c, edge) == false)
        std::cout << "4. Edge Point (10,0):    \033[32mPASS\033[0m (Returned False)" << std::endl;
    else
        std::cout << "4. Edge Point (10,0):    \033[31mFAIL\033[0m (Returned True)" << std::endl;

    return 0;
}