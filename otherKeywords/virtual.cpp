#include <iostream>

class Base {
	public:
		void func() {
			std::cout << "Base's func()" << std::endl;
		}
		
		virtual void func2() {
			std::cout << "Base's func2()" << std::endl;
		}
		
		virtual void func3() = 0;
		
		virtual ~Base() {
			std::cout << "Base destructor called" << std::endl;
		}
};

class Base2 {
	public:
		virtual void func() {
			std::cout << "Base2's func()" << std::endl;
		}
};

class Derived : public Base {
	public:
		/*Override*/
		void func() {
			std::cout << "Derived's func()" << std::endl;
		}
		
		/*Override*/
		void func2() {
			std::cout << "Derived's func2()" << std::endl;
		}
		
		/*Override*/
		void func3() {
			std::cout << "Derived's func3()" << std::endl;
		}
		
		~Derived() {
			std::cout << "Derived's destructor called" << std::endl;
		}
};

class Derived2 : public Base2 {
	public:
		/*Override*/
		void func() {
			std::cout << "Derived's func()" << std::endl;
		}
};

void test(Base2 b) {
	b.func();
}

int main(int argc, char** argv) {
	/*basic dynamic binding practice1*/
	std::cout << "--Practice1--" << std::endl;
	{
		Derived d;
		Base* b_ptr = &d;
		b_ptr->func();
		b_ptr->func2();
	}
	
	std::cout << std::endl;
	
	/*basic dynamic binding practice2*/
	std::cout << "--Practice2--" << std::endl;
	Base* b = new Derived();
	b->func3();
	
	std::cout << std::endl;
	
	/*basic dynamic binding practice3*/
	std::cout << "--Practice3--" << std::endl;
	Derived2 d2;
	test(d2);
	
	return 0;
}
