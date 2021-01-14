#include <iostream>
#include <string.h>

class Person {
	char name_[30];
	int age_;
	
	public:
		void set_person(const char* name, int age) {
			strcpy(name_, name);
			age_ = age;
		}
		
		void print_person() {
			std::cout << "Name: " << name_ << "\nAge: " << age_ << std::endl;
		}
};

int main(int argc, char** argv) {
	/*basic class practice*/
	Person person;
	
	person.set_person("pepero", 99);
	person.print_person();
	
	return 0;
}
