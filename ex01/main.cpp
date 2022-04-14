#include <stdint.h>
#include <cassert>

struct Data {
	int a;
	double b;
};

uintptr_t serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}

int main() {
	Data data = {0,0};
	Data *datap = &data;

	assert(datap == deserialize(serialize(datap)));
}
