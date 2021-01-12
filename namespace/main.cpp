#include <iostream>
#include "header1.h"
#include "header2.h"

extern int only_in_this_file; //links to namespace2.cpp

using ns1::foo;
using namespace ns1;

int main() {
	/*basic namespace practice1*/
	ns1::foo(); //calls header1.h -> ns1 namespace -> foo()
	ns2::foo(); //calls header1.h -> ns2 namespace -> foo()
	ns2::aaa(); //calls header2.h -> ns2 namespace -> aaa()
	ns2::func1(); //calls header2.h -> ns2 namespace -> func1()
	
	/*basic namespace practice2*/
	foo(); //calls header1.h -> ns1 namespace -> foo()
	boo(); //calls header1.h -> ns1 namespace -> boo()
	
	/*basic namespace practice3*/
	std::cout << only_in_this_file << std::endl;
	
	return 0;
}
