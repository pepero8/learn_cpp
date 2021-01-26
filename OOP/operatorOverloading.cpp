#include <iostream>
#include <string.h>

class Test {
	int n;
	
	friend std::ostream& operator<<(std::ostream& os, const Test& test);
	
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
			Test temp(n + test.n);
			return temp;
		}
		
		/*Overloading '+=' operator*/
		Test& operator+=(const Test& test) {
			(*this) = operator+(test);
			return *this;
		}
		
		Test& operator++() {
			n++;
			return *this;
		}
		
		Test operator++(int) {
			Test temp(*this);
			n++;
			return temp;
		}
		
		int getN() {
			return n;
		}
};

Test operator+(const Test& test1, const Test& test2) {
	return test1.operator+(test2);
}

std::ostream& operator<<(std::ostream& os, const Test& test) {
	os << test.n;
	return os;
}

class Integer {
	int data;
	
	public:
		Integer(int data): data(data) {}
		operator int() {
			return data;
		}
};


int main(int argc, char** argv) {
	/*basic operator overloading practice1*/
	std::cout << "--Practice1--" << std::endl;
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
	
	Test e = 12 + a; //operator+(Test(12), a);
	std::cout << "e: " << e.getN() << '\n' << std::endl;
	
	/*basic operator overloading practice2*/
	std::cout << "--Practice2--" << std::endl;
	Test f(50);
	std::cout << f << '\n' << std::endl;
	
	/*basic operator overloading practice3*/
	std::cout << "--Practice3--" << std::endl;
	Integer g = 1;
	int h = g + 2;
	std::cout << h << '\n' << std::endl;
	
	/*basic operator overloading practice4*/
	std::cout << "--Practice4--" << std::endl;
	Test i = 30;
	std::cout << i++ << std::endl;
	std::cout << i << std::endl;
	std::cout << ++i << std::endl;
	std::cout << i << std::endl;
	
	return 0;
}
