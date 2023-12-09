#include "Base.hpp"

Base::~Base() {}

Base * generateA(void) {
    return new A();
}

Base * generateB(void) {
    return new B();
}

Base * generateC(void) {
    return new C();
}

Base *	generate(void) {
	srand(time(0));
	int i = rand() % 3;
	Base* (*func[3])(void) = { generateA, generateB, generateC};
	return func[i]();
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
        std::cout << "Pointer : Class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Pointer : Class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Pointer : Class C" << std::endl;
}

void	identify(Base& p) {
    try 
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "Ref : Class A" << std::endl;
        (void)a;
        return;
    } 
    catch (const std::bad_cast& e) {}
    
    try 
    {
        B &b = dynamic_cast<B&>(p);
        std::cout << "Ref : Class B" << std::endl;
        (void)b;
        return;
    } 
    catch (const std::bad_cast& e) {}

    try 
    {
        C &c = dynamic_cast<C&>(p);
        std::cout << "Ref : Class C" << std::endl;
        (void)c;
        return;
    } 
    catch (const std::bad_cast& e) 
    {
        std::cerr << "Unknown type" << std::endl;
    }
}