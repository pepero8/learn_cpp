#include <iostream>

namespace ns2 {
	int aaa();
	
	int func1() {
		aaa(); //automatically calls "ns2::aaa();"
	}
}

namespace ns2 {
	int aaa() {
		std::cout << "Hi this is ns2's aaa" << std::endl;
	}
	
	void boo() {
		std::cout << "Hi this is ns2's boo" << std::endl;
	}
}
