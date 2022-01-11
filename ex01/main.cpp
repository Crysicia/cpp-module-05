#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	Bureaucrat *billy;
	Bureaucrat *bob;
	Bureaucrat *fanta;
	Bureaucrat *pyro;

	Form *basic_form;
	Form *epic_form;
	Form *impossible_form;
	Form *too_easy_form;

	std::cout << "---- Initialize Bureaucrats ----" << std::endl;
	try { billy = new Bureaucrat("Billy", 151); }
	catch (std::exception& e) { std::cout << "Error, exception catched: Billy: " << e.what() << std::endl; }

	try { bob = new Bureaucrat("Bob", 1); }
	catch (std::exception& e) { std::cout << "Error, exception catched: Bob: "  << e.what() << std::endl; }
	
	try { fanta = new Bureaucrat("Fanta", 150); }
	catch (std::exception& e) { std::cout << "Error, exception catched: Fanta: " << e.what() << std::endl; }
	
	try { pyro = new Bureaucrat("Pyro", 0); }
	catch (std::exception& e) { std::cout << "Error, exception catched: Pyro: " << e.what() << std::endl; }


	std::cout << std::endl << "---- Initialize Forms ----" << std::endl;
	try { basic_form = new Form("basic form", 50, 50); }
	catch (std::exception& e) { std::cout << "Error, exception catched: basic form: " << e.what() << std::endl; }

	try { epic_form = new Form("epic form", 1, 1); }
	catch (std::exception& e) { std::cout << "Error, exception catched: epic form: "  << e.what() << std::endl; }
	
	try { impossible_form = new Form("impossible form", 0, 0); }
	catch (std::exception& e) { std::cout << "Error, exception catched: impossible form: " << e.what() << std::endl; }
	
	try { too_easy_form = new Form("too easy form", 151, 151); }
	catch (std::exception& e) { std::cout << "Error, exception catched: too easy form: " << e.what() << std::endl; }

	Form basic_form_clone("basic form clone", 150, 150);
	Form epic_form_clone("epic form clone", 1, 1);



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

	Bureaucrat bob_copy(*bob);
	Bureaucrat bob_copy_copy;
	bob_copy_copy = bob_copy;

	std::cout << bob_copy << std::endl;
	std::cout << bob_copy_copy << std::endl;


	std::cout << std::endl << "---- Call incrementGrade() on Bureaucrats ----" << std::endl;
	try { bob->incrementGrade(); }
	catch (std::exception& e) { std::cout << "Error, exception catched: " << bob->getName() << ": " << e.what() << std::endl; }
	
	try { fanta->incrementGrade(); }
	catch (std::exception& e) { std::cout << "Error, exception catched: " << fanta->getName() << ": " << e.what() << std::endl; }
	

	std::cout << std::endl << "---- Call stream overloading on Forms ----" << std::endl;
	std::cout << *basic_form << std::endl;
	std::cout << *epic_form << std::endl;

	Form cool_form;
	cool_form = basic_form_clone;
	std::cout << basic_form_clone << std::endl;
	std::cout << cool_form << std::endl;


	std::cout << std::endl << "---- Call signForm() on Bureaucrats ----" << std::endl;
	bob->signForm(basic_form_clone);
	fanta->signForm(epic_form_clone);

	std::cout << std::endl << "---- Delete Bureaucrats ----" << std::endl;
	delete bob;
	delete fanta;

	std::cout << std::endl << "---- Delete Forms ----" << std::endl;
	delete basic_form;
	delete epic_form;

	return 0;	
}
