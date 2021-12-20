#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

#define FORM_COUNT 3

class Intern {
public:
	Intern();
	Intern(const Intern& copy);
	~Intern();
	Intern& operator=(const Intern& rhs);

	Form* createForm(std::string const& form_type, std::string const& target);

private:
	static Form* newRobotomyRequest(std::string const& target);
	static Form* newShrubberyCreation(std::string const& target);
	static Form* newPresidentialPardon(std::string const& target);
};

#endif
