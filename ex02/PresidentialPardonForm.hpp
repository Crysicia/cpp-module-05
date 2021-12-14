#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;
class PresidentialPardonForm : public Form {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const& target);
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
};

#endif
