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
        std::cout << "Class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Class C" << std::endl;
}

void	identify(Base& p) {
	identify(&p);
}