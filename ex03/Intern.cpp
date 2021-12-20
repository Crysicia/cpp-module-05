#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& copy) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& rhs) {
	std::cout << "Intern copy operator called" << std::endl;
	if ( this == &rhs ) { return *this; }
	return *this;
}

Form* Intern::createForm(std::string const& form_type, std::string const& target) {
	std::string form_name[FORM_COUNT] = { "robotomy request", "shrubbery creation", "presidential pardon" };
	Form* (*functions[FORM_COUNT])(std::string const&) = { Intern::newRobotomyRequest, Intern::newShrubberyCreation, Intern::newPresidentialPardon };
	Form* form;

	for (int i = 0; i < FORM_COUNT; i++) {
		if (form_type == form_name[i]) {
			try { form = functions[i](target); }
			catch(std::exception& e) { std::cout << "Could not create form because: " << e.what() << std::endl; };
			return form;
		}
	}
	std::cout << "Could not create form because: Form not found" << std::endl;
	return NULL;
}

Form* Intern::newRobotomyRequest(std::string const& target) {
	return new RobotomyRequestForm(target);
}

Form* Intern::newShrubberyCreation(std::string const& target) {
	return new ShrubberyCreationForm(target);
}

Form* Intern::newPresidentialPardon(std::string const& target) {
	return new PresidentialPardonForm(target);
}
