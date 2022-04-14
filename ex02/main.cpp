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
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "unknown derived class" << std::endl;
	}
}

void identify(Base &p) {
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {
		try {
			B b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::exception &e) {
			try {
				C c = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch (std::exception &e) {
				std::cout << "unknown derived class" << std::endl;
			}
		}
	}
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
