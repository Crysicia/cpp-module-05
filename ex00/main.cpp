#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat *billy = new Bureaucrat("Billy", 150);

	try {
		billy->decrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;	
}
