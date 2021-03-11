#include <iostream>

struct Comp {
	bool operator()(int a, int b) {
		return a < b;
	}
};

int main(int argc, char** argv) {
	//basic functor practice
	Comp comp;
	std::cout << comp(10, 20) << std::endl;
	
	return 0;
}