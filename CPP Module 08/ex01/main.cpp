#include "Span.hpp"
#include <iostream>

int main() {
    // Test case 1: Testing the basic functionality of Span class
    Span span(5);
    span.addNumber(10);
    span.addNumber(5);
    span.addNumber(15);
    span.addNumber(20);
    span.addNumber(25);
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl; // Expected output: 5
    std::cout << "Longest span: " << span.longestSpan() << std::endl;   // Expected output: 20

    // Test case 2: Testing the exception handling when Span is full
    try {
        Span span2(2);
        span2.addNumber(10);
        span2.addNumber(20);
        span2.addNumber(30); // This should throw a FullException
    } catch (const Span::FullException &e) {
        std::cout << "Exception caught: " << e.what() << std::endl; // Expected output: Span is full
    }

    // Test case 3: Testing the fillRand function
    Span span3(10);
    span3.fillRand();
    std::cout << "Shortest span: " << span3.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span3.longestSpan() << std::endl;

    return 0;
}