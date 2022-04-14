#include <iostream>
#include <iomanip>
#include <cmath>
#include <float.h>

enum NumType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
};

void	impossible() {
	std::cout << "number could not be parsed" << std::endl;
	exit(1);
}

		std::cout << "char: ";
		if (!isprint(d))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
int main(int argc, char **argv) {
	NumType t = NONE;

	if (argc != 2) {
		std::cout << "This program takes exaclty one argument" << std::endl;
		exit(1);
	}
	std::string s = argv[1];

	if (s.length() == 1 && !isdigit(s[0]))
		t = CHAR;
	else {
		for (unsigned int _i = 0; _i < s.length(); _i++) {
			if (!isdigit(s[_i])) {
				if (s[_i] == '-' && _i == 0)
					continue;
				if (s[_i] == '.') {
					if (t == NONE || t == INT)
						t = DOUBLE;
					else
					{
						std::cout << "two dots!" << std::endl;
						impossible();
					}
				} else if (s[_i] == 'f') {
					if (t == DOUBLE || t == INT)
						t = FLOAT;
					else
					{
						std::cout << "incorrect f!" << std::endl;
						impossible();
					}
				} else {
					std::cout << "wrong non-digit found!" << std::endl;
					impossible();
				}
			} else {
				if (t == NONE || t == INT)
					t = INT;
			}
		}
	}
	std::cout << std::showpoint;
	std::cout << std::setprecision(1) << std::fixed;
	if (t == CHAR) {
		std::cout << "char: '" << s[0]<< "'" << std::endl;
		std::cout << "int: " << static_cast<int>(s[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(s[0]) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(s[0]) << std::endl;
	}
	if (t == INT) {
		char *end;
		long i = std::strtol(s.c_str(), &end, 10);
		if (i == LONG_MAX || i > INT_MAX || i < INT_MIN) {
			std::cout << "overflow!" << std::endl;
			impossible();
		}
		std::cout << "char: ";
		if (!isprint(i))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << std::endl;
	}
	if (t == FLOAT) {
		char *end;
		double d = std::strtod(s.c_str(), &end);
		if (d == HUGE_VAL || d > FLT_MAX || d < -FLT_MAX) {
			std::cout << "overflow!" << std::endl;
			impossible();
		}
		std::cout << "char: ";
		if (!isprint(d))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		std::cout << "int: ";
		if (d > INT_MAX || d < INT_MIN)
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(d) << std::endl;
		std::cout << "float: " << d << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	if (t == DOUBLE) {
		char *end;
		double d = std::strtod(s.c_str(), &end);
		if (d == HUGE_VAL) {
			std::cout << "overflow!" << std::endl;
			impossible();
		}
		std::cout << "char: ";
		if (!isprint(d))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		std::cout << "int: ";
		if (d > INT_MAX || d < INT_MIN)
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(d) << std::endl;
		if (d > FLT_MAX || d < -FLT_MAX)
			std::cout << "impossible" << std::endl;
		else
			std::cout << "float: " << d << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}
