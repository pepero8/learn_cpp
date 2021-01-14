#include <iostream>

int main(int argc, char** argv) {
	/*basic dynamic memory allocation practice*/
	int* p = new int;
	
	*p = 1;
	
	std::cout << "*p: " << *p << std::endl;
	
	delete p;
	
	int* array = new int[3];
	
	array[0] = 1; array[1] = 2; array[2] = 3;
	
	for (int i = 0; i < 3; i++) {
		std::cout << array[i];
	}
	std::cout << std::endl;
	
	delete[] array;
	
	return 0;
}
