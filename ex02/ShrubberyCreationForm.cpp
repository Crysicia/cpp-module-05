#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", SHRUBBERY_CREATION_SIGN, SHRUBBERY_CREATION_EXEC, "default target") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) : Form("ShrubberyCreationForm", SHRUBBERY_CREATION_SIGN, SHRUBBERY_CREATION_EXEC, target) {
	std::cout << "ShrubberyCreationForm named constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	std::cout << "ShrubberyCreationForm copy operator called" << std::endl;
	if ( this == &rhs ) { return *this; }
	this->m_signed = rhs.m_signed;
	return *this;
}
