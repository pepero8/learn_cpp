#include <iostream>

void changeValue(int& p1, int* p2) {
	std::cout << "p1 address: " << &p1 << ", p2 address: " << &p2 << std::endl;
	p1++;
	*p2++;
}

int& returnRef() {
	static int a = 0;
	return a;
}

int& returnRef2(int& a) {
	a = 5;
	return a;
}

const int& returnRef3(const int& a) {
	return a;
}

int returnRef4() {
	int a = 6;
	return a;
}

int& returnRef5(int a) {
	a++;
	int& b = a;
	return b;
}

class A {
	int x;
	
	public:
		A(int c) : x(c) {}

		int& access_x() { return x; }
		int get_x() { return x; }
		void show_x() { std::cout << x << std::endl; }
};

int main(int argc, char** argv) {
	/*basic reference practice1*/
	std::cout << "--Practice1--" << std::endl;
	int a = 5;
	double b = 10.5;
	int* c = &a;
	
	int& another_a = a;
	double& another_b = b;
	int*& another_c = c;
	
	std::cout << "a: " << a << std::endl;
	another_a++;
	std::cout << "a: " << a << std::endl;
	a++;
	std::cout << "another_a: " << another_a << '\n' << std::endl;
	
	std::cout << "b: " << b << std::endl;
	another_b++;
	std::cout << "b: " << b << std::endl;
	b++;
	std::cout << "another_b: " << another_b << '\n' << std::endl;
	
	std::cout << "c: " << c << std::endl;
	another_c++;
	std::cout << "c: " << c << std::endl;
	c++;
	std::cout << "another_c: " << another_c << '\n' << std::endl;
	
	another_a = (int)b;
	std::cout << "a: " << a << '\n' << std::endl;
	
	std::cout << "a address: " << &a << ", c address: " << &c << std::endl;
	changeValue(a, c); //int& p1 = a, int* p2 = c;
	std::cout << "a: " << a << '\n' << std::endl;
	
	/*basic reference practice2*/
	std::cout << "--Practice2--" << std::endl;
	const int& r = 4;
	const char& ch = 'h';
	int i = r;
	char j = ch;
	
	std::cout << "i: " << i << std::endl;
	std::cout << "j: " << j << '\n' << std::endl;
	
	/*basic reference practice3*/
	std::cout << "--Practice3--" << std::endl;
	int arr[3] = {1, 2, 3};
	int (&ref)[3] = arr;
	
	int arr2[3][2] = {{1, 2}, {3, 4}, {5, 6}};
	int (&ref2)[3][2] = arr2;
	int (&ref3)[2] = ref2[1];
	
	for (int i = 0; i < 3; i++) {
		std::cout << ref[i];
	}
	std::cout << std::endl;
	
	ref[0] = 5; ref[1] = 6; ref[2] = 7;
	
	for (int i = 0; i < 3; i++) {
		std::cout << arr[i];
	}
	std::cout << std::endl;
	
	for (int i = 0; i < 2; i++) {
		std::cout << ref3[i];
	}
	std::cout << '\n' << std::endl;
	
	/*basic reference practice4*/
	std::cout << "--Practice4--" << std::endl;
	int d = returnRef();
	std::cout << "d: " << d << '\n' << std::endl;
	
	
	int e = returnRef2(d);
	std::cout << "e: " << e << std::endl;
	std::cout << "d: " << d << '\n' << std::endl;
	
	e = returnRef3(4);
	std::cout << "e: " << e << '\n' << std::endl;
	
	const int& f = returnRef4();
	const int& g = returnRef();
	std::cout << "f: " << f << std::endl;
	std::cout << "g: " << g << '\n' << std::endl;
	
	int h = returnRef5(6);
	std::cout << "h: " << h << '\n' << std::endl;
	
	/*basic reference practice5*/
	std::cout << "--Practice5--" << std::endl;
	A test(5);
	test.show_x();

	int& test_ref = test.access_x();
	test_ref = 4;
	test.show_x();

	int k = test.access_x();
	k = 3;
	test.show_x();

	int l = test.get_x();
	l = 1;
	test.show_x();
	
	test.access_x() = 3; //test.x = 3;
	test.show_x();
	
	return 0;
}
