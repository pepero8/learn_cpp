#include <iostream>

class Person {
	int age;
	
	public:
		Person() = default;
		
		Person(int _age) {
			age = _age;
		}
		
		Person(const Person& person) {
			age = person.age;
		}
		
		void changeAge(int _age) {
			age = _age;
		}
		
		void printAge() {
			std::cout << age << std::endl;
		}
};

class Animal {
	int age;
	
	public:
		Animal(int _age) {
			age = _age;
		}
		
		void printAge() {
			std::cout << age << std::endl;
		}
		
		void changeAge(int _age) {
			age = _age;
		}
};

int main(int argc, char** argv) {
	/*basic copy constructor practice*/
	Person p(50);
	Person p1;
	Person p2 = Person(p);
	Person p3 = p2;
	char* p4;
	
	std::cout << (p4) << std::endl;
	
	p1 = p2;
	
	p2.changeAge(99);
	
	p.printAge();
	p1.printAge();
	p2.printAge();
	p3.printAge();
	
	std::cout << std::endl;
	
	Animal a1(1);
	Animal a2 = Animal(a1); //calls default copy constructor
	
	a1.changeAge(2);
	
	a1.printAge();
	a2.printAge();
	
	return 0;
}
