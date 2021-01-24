#include <iostream>
#include <string.h>

class Person {
	char* name_;
	int age_;
	
	public:
		void set_person(const char* name, int age) {
			name_ = new char[strlen(name) + 1];
			strcpy(name_, name);
			age_ = age;
		}
		
		void print_person() {
			std::cout << "Name: " << name_ << "\nAge: " << age_ << std::endl;
		}
		
		/*destructor*/
		~Person() {
			std::cout << name_ << ": destructor called" << std::endl;
			if (name_ != NULL)
				delete[] name_;
		}
};

class Animal {
	int age_;
	int hunger_;
	int clean_;
	
	public:
		/*constructor*/
		Animal(int age, int hunger, int clean) : age_(age), hunger_(hunger), clean_(clean) {} //initializer list
		
		/*constructor*/
		Animal(int age_)
			: age_(age_), hunger_(0), clean_(100) {}
		
		/*constructor*/
		Animal() {
			age_ = 1;
			hunger_ = 0;
			clean_ = 100;
		}
		
		void setStat(int age, int hunger, int clean);
		void showStat();
};

class Test {
	static int count;
	
	public:
		Test() = default;
		void count_inc() {
			count++;
		}
		
		static void showCount() {
			std::cout << "count: " << count << std::endl;
		}
};

class Test2 {
	int var_;
	
	public:
		explicit Test2(int var): var_(var) {}
		static void function(Test2 t) {
			std::cout << "function called: " << t.var_ << std::endl;
		}
};

int Test::count = 0;

void Animal::setStat(int age, int hunger, int clean) {
	age_ = age;
	hunger_ = hunger;
	clean_ = clean;
}

void Animal::showStat() {
	std::cout << "age: " << age_ << "\nhunger: " << hunger_ << "\nclean: " << clean_ << std::endl;
}

int main(int argc, char** argv) {
	/*basic class practice1*/
	std::cout << "--Practice1--" << std::endl;
	Person person;
	Person* person2 = new Person;
	
	person.set_person("pepero", 99);
	person.print_person();
	
	person2->set_person("pepero2", 50);
	person2->print_person();
	
	delete person2;
	
	std::cout << std::endl;
	
	/*basic class practice2*/
	std::cout << "--Practice2--" << std::endl;
	Animal animal1(1, 0, 100);
	Animal animal2 = Animal(2, 50, 50);
	Animal animal3;
	Animal animal4(2);
	
	animal1.showStat();
	std::cout << std::endl;
	
	animal2.showStat();
	std::cout << std::endl;
	
	animal3.setStat(1, 0, 80);
	animal3.showStat();
	std::cout << std::endl;
	
	animal4.showStat();
	std::cout <<std::endl;
	
	/*basic class practice3*/
	std::cout << "--Practice3--" << std::endl;
	Test test1;
	Test test2;
	Test test3;
	
	test1.count_inc();
	test2.count_inc();
	test3.count_inc();
	
	Test::showCount();
	
	std::cout << std::endl;
	
	/*basic class practice4*/
	std::cout << "--Practice4--" << std::endl;
	
	Test2::function(Test2(5));
	//Test2::function(5); //complie error
	
	return 0;
}
