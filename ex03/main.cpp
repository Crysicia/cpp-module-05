#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	Bureaucrat *billy;
	Bureaucrat *bob;
	Bureaucrat *fanta;
	Bureaucrat *pyro;

	Form *shrubbery_creation_form;
	Form *robotomy_request_form;
	Form *presidential_pardon_form;
	Form *unsigned_presidential_pardon_form;

	Intern *kevin;

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
	try { shrubbery_creation_form = new ShrubberyCreationForm("file"); }
	catch (std::exception& e) { std::cout << "Error, exception catched: shrubbery_creation_form: " << e.what() << std::endl; }

	try { robotomy_request_form = new RobotomyRequestForm("Tyler"); }
	catch (std::exception& e) { std::cout << "Error, exception catched: robotomy_request_form: "  << e.what() << std::endl; }
	
	try { presidential_pardon_form = new PresidentialPardonForm("Dirk Gently"); }
	catch (std::exception& e) { std::cout << "Error, exception catched: presidential_pardon_form: " << e.what() << std::endl; }

	try { unsigned_presidential_pardon_form = new PresidentialPardonForm("Dirk Gently"); }
	catch (std::exception& e) { std::cout << "Error, exception catched: unsigned_presidential_pardon_form: " << e.what() << std::endl; }
	
	// ---- You cannot initialize From because it is now an abstract class
	// Form base_form("Impossible", 50, 50);

	std::cout << std::endl << "---- Initialize Intern ----" << std::endl;
	try { kevin = new Intern(); }
	catch (std::exception& e) { std::cout << "Error, exception catched: Kevin: " << e.what() << std::endl; }

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
	

	std::cout << std::endl << "---- Call stream overloading on Forms ----" << std::endl;
	std::cout << *shrubbery_creation_form << std::endl;
	std::cout << *robotomy_request_form << std::endl;
	std::cout << *presidential_pardon_form << std::endl;

	std::cout << std::endl << "---- Call signForm() on Bureaucrats ----" << std::endl;
	bob->signForm(*shrubbery_creation_form);
	fanta->signForm(*robotomy_request_form);
	bob->signForm(*robotomy_request_form);
	bob->signForm(*presidential_pardon_form);

	std::cout << std::endl << "---- Call stream overloading on Forms ----" << std::endl;
	std::cout << *shrubbery_creation_form << std::endl;
	std::cout << *robotomy_request_form << std::endl;
	std::cout << *presidential_pardon_form << std::endl;


	std::cout << std::endl << "---- Call executeForm() on Bureaucrats ----" << std::endl;
	bob->executeForm(*shrubbery_creation_form);
	bob->executeForm(*robotomy_request_form);
	bob->executeForm(*presidential_pardon_form);
	bob->executeForm(*unsigned_presidential_pardon_form);
	fanta->executeForm(*robotomy_request_form);

	std::cout << std::endl << "---- Call createForm() on Intern ----" << std::endl;
	Form *intern_shrubbery_creation_form;
	Form *intern_robotomy_request_form;
	Form *intern_presidential_pardon_form;
	Form *intern_unknown_form;

	try { intern_shrubbery_creation_form = kevin->createForm("shrubbery creation", "wall"); }
	catch(std::exception &e) { std::cout << "Error, exception catched: " << e.what() << std::endl; }

	try { intern_robotomy_request_form = kevin->createForm("robotomy request", "wall"); }
	catch(std::exception &e) { std::cout << "Error, exception catched: " << e.what() << std::endl; }

	try { intern_presidential_pardon_form = kevin->createForm("presidential pardon", "wall"); }
	catch(std::exception &e) { std::cout << "Error, exception catched: " << e.what() << std::endl; }

	try { intern_unknown_form = kevin->createForm("this forn doesn't exist", "wall"); }
	catch(std::exception &e) { std::cout << "Error, exception catched: " << e.what() << std::endl; }

	std::cout << std::endl << "---- Call stream overloading on Forms ----" << std::endl;
	std::cout << *intern_shrubbery_creation_form << std::endl;
	std::cout << *intern_robotomy_request_form << std::endl;
	std::cout << *intern_presidential_pardon_form << std::endl;

	std::cout << std::endl << "---- Delete Bureaucrats ----" << std::endl;
	delete bob;
	delete fanta;

	std::cout << std::endl << "---- Delete Forms ----" << std::endl;
	delete shrubbery_creation_form;
	delete robotomy_request_form;
	delete presidential_pardon_form;
	delete unsigned_presidential_pardon_form;

	delete intern_shrubbery_creation_form;
	delete intern_robotomy_request_form;
	delete intern_presidential_pardon_form;

	std::cout << std::endl << "---- Delete Intern ----" << std::endl;
	delete kevin;

	return 0;	
}
