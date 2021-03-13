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

template <typename T>
void print(T arg) {
	std::cout << "first print():" << arg << std::endl;
}

template <typename... Types>
void print(Types... args) {
	std::cout << "second print()" << std::endl;
	print(args...);
}

template <typename T, typename... Types>
void print(T arg, Types... args) {
	std::cout << "third print():" << arg << std::endl;
	print(args...);
}

template <typename Num>
int sum_all(Num n) { return n; }

template <typename Num, typename... Nums>
int sum_all(Num n, Nums... ns) {
	return n + sum_all(ns...);
}

template <typename... Nums>
double average(Nums... nums) {
	return static_cast<double>(sum_all(nums...)) / sizeof...(nums);
}

template <typename Int, typename... Ints>
int sum_all2(Int start, Ints... nums) {
	return (start + ... + nums); //Fold expression
}

template <typename T>
void do_something(T arg) {
	std::cout << "do something with: " << arg << std::endl;
}

template <typename... Types>
void do_many_things(Types... args) {
	(... , do_something(args));
	//(do_something(args), ...);
}

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
	
	std::cout << std::endl;
	
	//basic template practice6
	std::cout << "--Practice6--" << std::endl;
	print(1, 3.14, "abc");
	print(1);
	
	std::cout << std::endl;
	
	//basic template practice7
	std::cout << "--Practice7--" << std::endl;
	std::cout << "average: " << average(1, 4, 2, 3, 10) << std::endl;
	
	std::cout << std::endl;
	
	//basic template practice8
	std::cout << "--Practice8--" << std::endl;
	std::cout << sum_all2(1, 2, 3, 4, 5) << std::endl;
	
	std::cout << std::endl;
	
	//basic template practice9
	std::cout << "--Practice9--" << std::endl;
	do_many_things("hello", 1, 2, 3.14, std::string("world"));
	
	return 0;
}