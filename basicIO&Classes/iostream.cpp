#include <iostream>

int main(int argc, char** argv) {
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
	
	return 0;
}
