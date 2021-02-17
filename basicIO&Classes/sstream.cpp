#include <iostream>
#include <sstream>
#include <string>

double to_num(std::string s) {
	std::istringstream ss(s);
	double temp;
	
	ss >> temp;
	return temp;
}

std::string to_str(double d) {
	std::ostringstream ss;
	
	ss << d;
	
	return ss.str();
}

int main(int argc, char** argv) {
	std::cout << "1 + 2 = " << to_num("1") + to_num("2") << std::endl;
	std::cout << "1 + 2 = " << to_str(1 + 2) << std::endl;
	
	return 0;
}
