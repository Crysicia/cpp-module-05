#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat *billy;
	Bureaucrat *bob;
	Bureaucrat *fanta;
	Bureaucrat *pyro;

	std::cout << "---- Initialize Bureaucrats ----" << std::endl;
	try { billy = new Bureaucrat("Billy", 151); }
	catch (std::exception& e) { std::cout << "Error, exception catched: Billy: " << e.what() << std::endl; }

	try { bob = new Bureaucrat("Bob", 1); }
	catch (std::exception& e) { std::cout << "Error, exception catched: Bob: "  << e.what() << std::endl; }
	
	try { fanta = new Bureaucrat("Fanta", 150); }
	catch (std::exception& e) { std::cout << "Error, exception catched: Fanta: " << e.what() << std::endl; }
	
	try { pyro = new Bureaucrat("Pyro", 0); }
	catch (std::exception& e) { std::cout << "Error, exception catched: Pyro: " << e.what() << std::endl; }


	std::cout << std::endl << "---- Call decrementGrade() on Bureaucrats ----" << std::endl;
	try { bob->decrementGrade(); }
	catch (std::exception& e) { std::cout << "Error, exception catched: " << bob->getName() << ": " << e.what() << std::endl; }
	
	try { fanta->decrementGrade(); }
	catch (std::exception& e) { std::cout << "Error, exception catched: " << fanta->getName() << ": " << e.what() << std::endl; }

	bob->incrementGrade();
	fanta->incrementGrade();


	std::cout << std::endl << "---- Call stream overloading on Bureaucrats ----" << std::endl;
	std::cout << *bob << std::endl;
	std::cout << *fanta << std::endl;


	std::cout << std::endl << "---- Call incrementGrade() on Bureaucrats ----" << std::endl;
	try { bob->incrementGrade(); }
	catch (std::exception& e) { std::cout << "Error, exception catched: " << bob->getName() << ": " << e.what() << std::endl; }
	
	try { fanta->incrementGrade(); }
	catch (std::exception& e) { std::cout << "Error, exception catched: " << fanta->getName() << ": " << e.what() << std::endl; }
	

	std::cout << std::endl << "---- Delete Bureaucrats ----" << std::endl;
	delete bob;
	delete fanta;

	return 0;	
}
