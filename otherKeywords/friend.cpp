#include <iostream>

class A {
	private:
		int a_private;
		
	friend class B;
	friend int func2();
};

class B {
	private:
		int b_private;
	
	public:
		int func1() {
			A a;
			a.a_private = 1;
			
			return a.a_private;
		}
};

int func2() {
	A a;
	a.a_private = 2;
	
	return a.a_private;
}

int main(int argc, char** argv) {
	/*basic friend practice*/
	int temp;
	temp = func2();
	std::cout << temp << std::endl;
	
	B b;
	temp = b.func1();
	std::cout << temp << std::endl;
	
	return 0;
}
