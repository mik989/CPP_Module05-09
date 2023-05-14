#include "base.hpp"
#include "a.hpp"
#include "b.hpp"
#include "c.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>


static base* generate(void)
{
    std::srand(std::time(nullptr));
    int i = std::rand() % 3;

    switch (i)
    {
    case 0:
        return (new A()); 
    case 1: 
        return (new B()); 
    case 2: 
        return (new C()); 
    default:
        return NULL;
    }
}

void    identify (base& ref)
{
    try
    {
        A& a = dynamic_cast <A&>(ref);
        std::cout << "identify CLASS: A&" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
    }

    try
    {
        B& b = dynamic_cast <B&>(ref);
        std::cout << "identify CLASS: B&" << std::endl;
        return ;

    }
    catch(const std::exception& e)
    {
    }

    try
    {
        C& c = dynamic_cast <C&>(ref);
        std::cout << "identify CLASS: C&" << std::endl;
        return ;

    }
    catch(const std::exception& e)
    {
    }
    
}

void    identify (base* ref)
{
    A* a = dynamic_cast <A*>(ref);
    B* b = dynamic_cast <B*>(ref);
    C* c = dynamic_cast <C*>(ref);

    if(a)
    {
        std::cout << "identify CLASS: A*" << std::endl;
    }
    else if (b)
    {
        std::cout << "identify CLASS: B*" << std::endl;
    }
    else if (c)
    {
        std::cout << "identify CLASS: C*" << std::endl;
    }
    else
        return ;
}

int main()
{
    base* bas;
    base* at;
    bas = generate();
    at = generate();

    identify(bas);
    identify(*bas);
    identify(at);
    identify(*at);

    if (bas)
        delete bas;
    if (at)
        delete at;
}