// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Header.h"
#include <iostream>

int main()
{
    Solution s;
    std::cout << s.myAtoi("00000-42a12340") << std::endl;
    std::cout << s.myAtoi(" -123") << std::endl;
    std::cout<<s.myAtoi("9999999999") << std::endl;
    std::cout<<s.myAtoi("4193 with words") << std::endl;
    std::cout<<s.myAtoi("3.14159") << std::endl;
    std::cout<<s.myAtoi("21474836460") << std::endl;
    std::cout<<s.myAtoi("0100") << std::endl;
    std::cout<<s.myAtoi("+-12") << std::endl;
    std::cout<<s.myAtoi("-") << std::endl;
    std::cout<<s.myAtoi("+1") << std::endl;
    std::cout<<s.myAtoi("  0000000000012345678") << std::endl; // should be 12345678
    std::cout<<s.myAtoi(" -0012a42") << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
