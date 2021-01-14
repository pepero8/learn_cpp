#include <iostream>

int main(int argc, char** argv) {
	/*basic io practice*/
	char name[20];
	int age;
	
	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << "Enter your age: ";
	std::cin >> age;
	
	std::cout << std::endl << "Your name: " << name << std::endl;
	std::cout << "Your age: " << age << std::endl;
	
	return 0;
}
