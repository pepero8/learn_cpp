#include <iostream>

class Base {
	public:
		virtual void func() {
			std::cout << "Base's func()" << std::endl;
		}
		
		virtual void func2() {
			std::cout << "Base's func2()" << std::endl;
		}
};

class Derived : public Base {
	public:
		void func() const override { //compile error
			std::cout << "Derived's func()" << std::endl;
		}
		
		/*Overriding*/
		void func2() override {
			std::cout << "Derived's func2()" << std::endl;
		}
};

int main(int argc, char** argv) {
	/*basic dynamic binding practice*/
	Derived d;
	Base* b_ptr = &d;
	b_ptr->func();
	b_ptr->func2();
	
	return 0;
}
