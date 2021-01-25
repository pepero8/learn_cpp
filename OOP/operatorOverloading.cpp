#include <iostream>
#include <string.h>

class Test {
	int n;
	
	public:
		/*constructor*/
		Test(int num): n(num) {}
		
		Test(const Test& test): n(test.n) {
			std::cout << "copy constructor called" << std::endl;
		}
		
		/*overloading '==' operator*/
		bool operator==(const Test& test) const {
			return n == test.n;
		}
		
		/*Overloading '=' operator*/
		Test& operator=(const Test& test) {
			std::cout << "'=' operator called" << std::endl;
			n = test.n;
			return *this;
		}
		
		/*Overloading '+' operator*/
		Test operator+(const Test& test) const {
			Test temp(test.n);
			return temp;
		}
		
		/*Overloading '+=' operator*/
		Test& operator+=(const Test& test) {
			(*this) = (*this) + test;
			return *this;
		}
		
		int getN() {
			return n;
		}
};

int main(int argc, char** argv) {
	/*basic operator overloading practice*/
	Test a(10);
	Test b(20);
	
	Test c = a; //calls copy constructor
	std::cout << "c: " << c.getN() << std::endl;
	c = b; //c.operator(b);
	std::cout << "c: " << c.getN() << std::endl;
	
	Test d = a + b;
	std::cout << "d: " << d.getN() << std::endl;
	
	std::cout << "a: " << a.getN() << std::endl;
	std::cout << "b: " << b.getN() << std::endl;
	
	return 0;
}
