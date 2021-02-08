#include <iostream>
#include <string>

int main(int argc, char** argv) {
	/*basic class string practice1*/
	std::cout << "--Practice1--" << std::endl;
	std::string s = "abc";
	
	std::cout << s << std::endl;
	
	std::cout << std::endl;
	
	/*basic class string practice2*/
	std::cout << "--Practice2--" << std::endl;
	std::string s1 = "def";
	std::string s2 = s;
	
	std::cout << "length of " << s << ": " << s.length() <<  std::endl;
   	std::cout << s << " + " << s1 << ": " << s + s1 <<  std::endl;

  	if (s == s2) {
    	std::cout << s << " and " << s2 << " are equal" <<  std::endl;
  	}
  	if (s != s1) {
     	std::cout << s << " and " << s1 << " are not equal " <<  std::endl;
  	}
	
	return 0;
}
