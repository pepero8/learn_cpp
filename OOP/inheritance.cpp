#include <iostream>

class Base {
	protected:
		int parent_var;
	
	public:
		int var;
		
		Base(): var(10) {
			std::cout << "Base's constructor" << std::endl;
			function();
		}
		
		void function() {
			std::cout << var << std::endl;
		}
};

class Base2 {
	public:
		Base2() {
			std::cout << "Base2's constructor" << std::endl;
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
		
		/*Override*/
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

class Derived4 : public Base, public Base2 {
	public:
		Derived4() {
			std::cout << "Derived4's constructor" << std::endl;
		}
};

class Derived5 : public Base2, public Base {
	public:
		Derived5() {
			std::cout << "Derived5's constructor" << std::endl;
		}
};

class Derived6 : public virtual Base {
	public:
		int b;
		Derived6() : b(6) {
			std::cout << "Derived6's constructor"
					  << "\nDerived6's var: " << var
					  << "\nDerived6's b: " << b
					  << std::endl;
		}
};

class Derived7 : public virtual Base {
	public:
		int b;
		Derived7() : b(7) {
			std::cout << "Derived7's constructor"
					  << "\nDerived7's var: " << var
					  << "\nDerived7's b: " << b
					  << std::endl;
		}
};

class Derived8 : public Derived6, public Derived7 {
	public:
		Derived8() {
			std::cout << "Derived8's constructor"
					  << "\nDerived8's var: " << var
					  //<< "\nDerived8's b: " << b -> ambiguous
					  << std::endl;
		}
};

void test(Base& b) {
	b.function();
}

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
	
	test(d4);
	
	std::cout << std::endl;
	
	/*basic inheritance practice6*/
	std::cout << "--Practice6--" << std::endl;
	Derived4 d5;
	std::cout << std::endl;
	Derived5 d6;
	
	std::cout << std::endl;
	
	/*basic inheritance practice7*/
	std::cout << "--Practice7--" << std::endl;
	Derived7 d7;
	//std::cout << d7.var << std::endl;
	std::cout << std::endl;
	Derived8 d8;
	//std::cout << d8.var << std::endl;
	//std::cout << d8.b << std::endl;
	
	return 0;
}
