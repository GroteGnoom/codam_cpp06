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

template <typename T> void print_char(T d) {
	std::cout << "char: ";
	if (!isprint(d))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
}

template <typename T> void print_int(T d) {
	std::cout << "int: ";
	if (d > INT_MAX || d < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
}

template <typename T> void print_float(T d) {
	std::cout << "float: ";
	if (d > FLT_MAX || d < -FLT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(d) << "f" << std::endl;
}

template <typename T> void print_double(T d) {
	std::cout << "double: ";
		std::cout << static_cast<double>(d) << std::endl;
}

template <typename T> void print_numbers(T d) {
	print_char(d);
	print_int(d);
	print_float(d);
	print_double(d);
}

NumType get_numtype(std::string s) {
	NumType t = NONE;

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
	return (t);
}

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "This program takes exaclty one argument" << std::endl;
		exit(1);
	}

	std::string s = argv[1];

	if (s == "nan" || s == "-inf" || s == "+inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << s << "f" << std::endl;
		std::cout << "double: " << s << std::endl;
		return 0;
	}
	if (s == "nanf" || s == "-inff" || s == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << s << std::endl;
		std::cout << "double: " << s.substr(0, s.size()-1) << std::endl;
		return 0;
	}

	NumType t = get_numtype(s);

	std::cout << std::showpoint;
	std::cout << std::setprecision(1) << std::fixed;
	if (t == CHAR) {
		print_numbers(s[0]);
	}
	if (t == INT) {
		char *end;
		long i = std::strtol(s.c_str(), &end, 10);
		if (i == LONG_MAX || i > INT_MAX || i < INT_MIN) {
			std::cout << "overflow!" << std::endl;
			impossible();
		}
		print_numbers(i);
	}
	if (t == FLOAT) {
		char *end;
		double d = std::strtod(s.c_str(), &end);
		if (d == HUGE_VAL || d > FLT_MAX || d < -FLT_MAX) {
			std::cout << "overflow!" << std::endl;
			impossible();
		}
		print_numbers(d);
	}
	if (t == DOUBLE) {
		char *end;
		double d = std::strtod(s.c_str(), &end);
		if (d == HUGE_VAL) {
			std::cout << "overflow!" << std::endl;
			impossible();
		}
		print_numbers(d);
	}
}
