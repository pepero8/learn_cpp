#include <iostream>

//mutable int changeable;
class Integer {
	int n_;
	
	public:
		Integer(int n): n_(n) {}
		
		int getN() {
			return n_;
		}
};

class Test {
	mutable Integer* i;
	
	public:
		Test(int n) {
			i = new Integer(n);
		}
		
		void function() const {
			delete i;
			i = new Integer(8);
		}
		
		void print() {
			std::cout << i->getN() << std::endl;
		}
};

int main(int argc, char** argv) {
	/*basic mutable practice*/
	Test t(1);
	
	t.print();
	t.function();
	t.print();
	
	return 0;
}
