#include <iostream>

void print(int a) {
	std::cout << "int: " << a << std::endl;
}

/*
int print(int a) {
	std::cout << "int: " << a << std::endl;
	return 0;
}
*/

void print(int a, int b) {
	std::cout << "int: " << a << "int: " << b << std::endl;
}

void print(char a) {
	std::cout << "char: " << a << std::endl;
}

int main(int argc, char** argv) {
	/*basic method overloading practice*/
	int a = 0, b = 2;
	short s = 1;
	char c = 'a';
	double d = 3.5f;
	
	print(a);
	printf(a, b);
	print(s); //-> calls print(int a)
	print(c);
	//print(d); -> error
	
	return 0;
}
