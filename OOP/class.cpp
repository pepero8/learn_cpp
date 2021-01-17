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
		Animal(int age, int hunger, int clean) {
			age_ = age;
			hunger_ = hunger;
			clean_ = clean;
		}
		
		Animal() {
			age_ = 1;
			hunger_ = 0;
			clean_ = 100;
		}
		
		void setStat(int age, int hunger, int clean);
		void showStat();
};

class Test {
	public:
		Test() = default;
		void test() {
			std::cout << "Test created" << std::endl;
		}
};

void Animal::setStat(int age, int hunger, int clean) {
	age_ = age;
	hunger_ = hunger;
	clean_ = clean;
}

void Animal::showStat() {
	std::cout << "age: " << age_ << "\nhunger: " << hunger_ << "\nclean: " << clean_ << std::endl;
}

int main(int argc, char** argv) {
	/*basic class practice*/
	Person person;
	Person* person2 = new Person;
	Animal animal1(1, 0, 100);
	Animal animal2 = Animal(2, 50, 50);
	Animal animal3;
	
	person.set_person("pepero", 99);
	person.print_person();
	
	person2->set_person("pepero2", 50);
	person2->print_person();
	
	delete person2;
	
	std::cout << std::endl;
	
	animal1.showStat();
	std::cout << std::endl;
	animal2.showStat();
	std::cout << std::endl;
	animal3.setStat(1, 0, 80);
	animal3.showStat();
	std::cout << std::endl;
	
	Test test;
	test.test();
	
	return 0;
}
