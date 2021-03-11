#include <iostream>

template <typename T, typename A>
class Test {
	T data1;
	A data2;
	
	public:
		Test(T data1, A data2) : data1(data1), data2(data2) {}
		T getData1() {
			return data1;
		}
		A getData2() {
			return data2;
		}
};

template <typename A>
class Test<int, A> {
	int data1;
	A data2;
	
	public:
		Test(int data1, A data2) : data1(data1), data2(data2) {}
		int getData1() {
			return data1 * 2;
		}
		A getData2() {
			return data2;
		}
};

template <typename A>
A function(A& a) {
	return a;
}

template <typename A, int num>
int function2(A& a) {
	return a + num;
}

template <typename A, int num = 5>
int function3(A& a) {
	return a + num;
}

template <typename T, int num>
struct Add {
	T operator()(T a) {
		return a + num;
	}
};

template <typename T, typename Add = Add<T, 7>>
class Test2 {
	public:
		T addNum(const T& a) {
			Add add;
			return add(a);
		}
};

int main(int argc, char** argv) {
	//basic template practice1
	std::cout << "--Practice1--" << std::endl;
	Test<char, std::string> test('A', "hello");
	std::cout << test.getData1() << ", " << test.getData2() << std::endl;
	
	std::cout << std::endl;
	
	//basic template practice2
	std::cout << "--Practice2--" << std::endl;
	Test<int, std::string> test2(10, "world");
	Test<double, std::string> test3(10, "world");
	std::cout << test2.getData1() << ", " << test2.getData2() << std::endl;
	std::cout << test3.getData1() << ", " << test3.getData2() << std::endl;
	
	std::cout << std::endl;
	
	//basic template practice3
	std::cout << "--Practice3--" << std::endl;
	int a = 5;
	std::string b = "abcd";
	std::cout << function(a) << std::endl;
	std::cout << function(b) << std::endl;
	
	std::cout << std::endl;
	
	//basic template practice4
	std::cout << "--Practice4--" << std::endl;
	int c = 3;
	std::cout << function2<int, 1>(c) << std::endl;
	//std::cout << function2(c) << std::endl; //compile error
	std::cout << function3(c) << std::endl;
	std::cout << function3<int, 10>(c) << std::endl;
	
	std::cout << std::endl;
	
	//basic template practice5
	std::cout << "--Practice5--" << std::endl;
	Test2<int> test4;
	std::cout << test4.addNum(7) << std::endl;
	
	return 0;
}