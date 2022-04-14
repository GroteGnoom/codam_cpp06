#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base *generate(void) {
	int r;
	std::srand(std::time(NULL));
	r = rand() % 3;
	if (r == 0)
		return new A;
	if (r == 1)
		return new B;
	return new C;
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	}
	if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	}
	if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	}
}

void identify(Base &p) {
	identify(&p);
}

int main() {
	Base *b1 = new A;
	Base *b2 = new B;
	Base *b3 = new C;
	identify(b1);
	identify(b2);
	identify(b3);
	identify(*b1);
	identify(*b2);
	identify(*b3);
	delete b1;
	delete b2;
	delete b3;
}
