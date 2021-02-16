#include <iostream>

void ioPractice1() {
	int a;
	
	while(true) {
		std::cin >> a;
		
		if (std::cin.fail()) {
			std::cout << "bad input" << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else if (a == 1) break;
	}
}

void ioPractice2() {
	int a;
	
	while(true) {
		std::cin.setf(std::ios_base::hex, std::ios_base::basefield);
		std::cin >> a;
		//std::cin >> std::hex >> a;
		
		if (std::cin.fail()) {
			std::cout << "bad input" << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else {
			std::cout << "a: " << /*std::hex <<*/  a << std::endl;
			if (a == 1) break;
		}
			
	}
}

void ioPractice3() {
	std::string s;
	char c;
	
	while (true) {
		//c = std::cin.rdbuf()->snextc();
		std::streambuf* bptr = std::cin.rdbuf();
		c = bptr->snextc();
		std::cout << "next char: " << c << std::endl;
		if (c == '1') break;
	}
}

int main(int argc, char** argv) {
	//ioPractice1();
	//ioPractice2();
	//ioPractice3();
	
	return 0;
}
