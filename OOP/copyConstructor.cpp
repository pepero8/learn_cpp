#include <iostream>
#include <string.h>

class Person {
	int age;
	char* name;
	
	public:
		Person() = default;
		
		Person(int _age) {
			age = _age;
			name = NULL;
		}
		
		Person(int _age, const char* _name) {
			age = _age;
			name = new char[strlen(_name) + 1];
			strcpy(name, _name);
		}
			
		/*copy constructor*/
		Person(const Person& person) {
			age = person.age;
			name = new char[strlen(person.name) + 1];
			strcpy(name, person.name);
		}
		
		void changeAge(int _age) {
			age = _age;
		}
		
		void print() {
			std::cout << "(Person)age: " << age << ", name: " << name << std::endl;
		}
		
		~Person() {
			std::cout << "(Person) destructor called" << std::endl;
			if (name != NULL) delete[] name;
		}
};

class Animal {
	int age;
	char* type;
	
	public:
		/*constructor*/
		Animal(int _age, const char* _type) {
			age = _age;
			type = new char[strlen(_type) + 1];
			strcpy(type, _type);
		}
		
		void print() {
			std::cout << "(Animal)age: " << age << ", type: " << type << std::endl;
		}
		
		void changeAge(int _age) {
			age = _age;
		}
		
		void changeType(const char* _type) {
			strcpy(type, _type);
		}
		
		~Animal() {
			std::cout << "(Animal) destructor called" << std::endl;
			if (type != NULL) delete[] type;
		}
};

int main(int argc, char** argv) {
	/*basic copy constructor practice1*/
	std::cout << "--Practice1--" << std::endl;
	Person p(50, "pepero");
	Person p1;
	Person p2 = p;
	Person p3 = p2;
	Person p4 = Person(p3);
	
	p1 = p2;
	
	p2.changeAge(99);
	
	p.print();
	p1.print();
	p2.print();
	p3.print();
	p4.print();
	
	std::cout << std::endl;
	
	/*basic copy constructor practice2*/
	std::cout << "--Practice2--" << std::endl;
	Animal a1(1, "dog");
	//Animal a2 = Animal(a1); //calls default copy constructor, 'type' variable is shallow copied -> at the end of the program, it terminates with error
	
	a1.changeAge(2);
	a1.changeType("cat");
	
	a1.print();
	//a2.print();
	
	return 0;
}
