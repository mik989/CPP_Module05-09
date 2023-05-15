#include "Span.hpp"

int main()
{
    
    int min = 0;
    int max = 10000;
    std::cout << "CREO LA CLASSE SPAN" << std::endl;
    std::cout << std::endl;
    Span sp = Span(10006);
    std::cout << "--- AGGIUNGO 5 NUMERI ---" << std::endl;
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "--- NUMERI AGGIUNTI ---" << std::endl;
    std::cout << std::endl;
    std::cout << "--- STAMPO I VALORI SHORTEST E LONGEST ---" << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << std::endl;
    std::cout << "--- FINE ---" << std::endl;
    sp.addSomeNumbers(min, max);
    return 0;
}