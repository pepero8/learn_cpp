#include <iostream>

class Base {
	protected:
		int parent_var;
	
	public:
		int var;
		
		Base(): var(10) {
			function();
		}
		
		void function() {
			std::cout << var << std::endl;
		}
};

class Derived : public Base {
	int var;
	
	public:
		Derived(): Base() {
			var = 20;
			function();
		}
};

class Derived2 : public Base {
	int var;
	
	public:
		Derived2(): Base() {
			var = 20;
			function();
		}
		
		/*Overriding*/
		void function() {
			std::cout << var << std::endl;
		}
		
		void change() {
			parent_var = 30;
			std::cout << parent_var << std::endl;
		}
};

class Derived3 : private Base {
	public:
		Derived3() : Base() {}
};

int main(int argc, char** argv) {
	/*basic inheritance practice1*/
	std::cout << "--Practice1--" << std::endl;
	Derived d;
	
	std::cout << std::endl;
	
	/*basic inheritance practice2*/
	std::cout << "--Practice2--" << std::endl;
	Derived2 d2;
	
	std::cout << std::endl;
	
	/*basic inheritance practice3*/
	std::cout << "--Practice3--" << std::endl;
	d2.change();
	
	std::cout << std::endl;
	
	/*basic inheritance practice4*/
	std::cout << "--Practice4--" << std::endl;
	Base b;
	Derived3 d3;
	std::cout << b.var << std::endl;
	//std::cout << d3.var << std::endl; -> var inaccessible
	
	std::cout << std::endl;
	
	/*basic inheritance practice5*/
	std::cout << "--Practice5--" << std::endl;
	Derived2 d4;
	
	Base* ptr = &d4; //up casting
	
	ptr->function();
	
	return 0;
}
