#include <iostream>
#include <string.h>

struct person {
	char name[30];
	int age;
};

int main(int argc, char** argv) {
	/*basic dynamic memory allocation practice*/
	int* p = new int;
	
	*p = 1;
	
	std::cout << "*p: " << *p << '\n' << std::endl;
	
	delete p;
	
	int* array = new int[3];
	
	array[0] = 1; array[1] = 2; array[2] = 3;
	
	for (int i = 0; i < 3; i++) {
		std::cout << array[i];
	}
	std::cout << '\n' << std::endl;
	
	delete[] array;
	
	struct person* person_ptr = new struct person;
	
	strcpy(person_ptr->name, "pepero");
	person_ptr->age = 99;
	
	std::cout << person_ptr->name << " " << person_ptr->age << std::endl;
	
	return 0;
}
