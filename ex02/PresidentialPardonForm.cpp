#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonform", PRESIDENTIAL_PARDON_SIGN, PRESIDENTIAL_PARDON_EXEC, "default target") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) : Form("PresidentialPardonform", PRESIDENTIAL_PARDON_SIGN, PRESIDENTIAL_PARDON_EXEC, target) {
	std::cout << "PresidentialPardonForm named constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	std::cout << "PresidentialPardonForm copy operator called" << std::endl;
	if ( this == &rhs ) { return *this; }
	this->m_signed = rhs.m_signed;
	return *this;
}
