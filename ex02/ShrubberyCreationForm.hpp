#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;
class ShrubberyCreationForm : public Form {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
};

#endif
