#include <iostream>
#include <fstream>
#include <string>

void fileIOPractice1() {
	std::ifstream in("test.txt");
	std::string s;
	int x;
	
	if (!in.is_open()) {
		std::cout << "cannot open file" << std::endl;
		return;
	}

	in >> s;
	
	std::cout << "file content: " << s << std::endl;
	
	in.close();
	in.open("test.txt");
	
	if (!in.is_open()) {
		std::cout << "cannot open file" << std::endl;
		return;
	}

	in >> x;
	
	std::cout << "file content: " << x << std::endl;
}

void fileIOPractice2() {
	std::ifstream in("test2.txt", std::ios::binary);
	int x;
	
	if (!in.is_open()) {
		std::cout << "cannot open file" << std::endl;
		return;
	}
	
	in.read((char*)(&x), 4);
	
	std::cout << "file content: " << x << std::endl;
}

void fileIOPractice3() {
	std::ifstream in("test2.txt");
	std::string s;
	
	if (!in.is_open()) {
		std::cout << "cannot open file" << std::endl;
		return;
	}
	
	in.seekg(0, std::ios::end);
	int size = in.tellg();
	
	s.resize(size);
	
	in.seekg(0, std::ios::beg);
	
	in.read(&s[0], size);
	
	std::cout << "file content: \n" << s << std::endl;
}

void fileIOPractice4() {
	std::ifstream in("test2.txt");
	char buf[100];
	
	if (!in.is_open()) {
		std::cout << "cannot open file" << std::endl;
		return;
	}
	
	while(in.getline(buf, 100)) {
		std::cout << "next line: " << buf << std::endl;
	}
}

void fileIOPractice5() {
	std::ofstream out("test2.txt");
	
	if (!out.is_open()) {
		std::cout << "cannot open file" << std::endl;
		return;
	}
	
	out << "Hello world, this is a long sentence";
}

void fileIOPractice6() {
	std::ofstream out("test2.txt", std::ios::app);
	//std::ofstream out("test2.txt", std::ios::ate);
	//std::ofstream out("test2.txt", std::ios::trunc);
	
	if (!out.is_open()) {
		std::cout << "cannot open file" << std::endl;
		return;
	}
	
	out << "append!";
}

int main(int argc, char** argv) {
	//fileIOPractice1();
	//fileIOPractice2();
	//fileIOPractice3();
	//fileIOPractice4();
	//fileIOPractice5();
	//fileIOPractice6();
	
	return 0;
}
