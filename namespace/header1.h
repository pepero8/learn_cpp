#include <iostream>

namespace ns1 {
	int foo() {
		std::cout << "Hi this is ns1's foo" << std::endl;
	}
	void boo() {
		std::cout << "Hi this is ns1's boo" << std::endl;
	}
}

namespace ns2 {
	int foo() {
		std::cout << "Hi this is ns2's foo" << std::endl;
	}
}
