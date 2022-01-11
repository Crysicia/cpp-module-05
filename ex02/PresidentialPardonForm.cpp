#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonform", PRESIDENTIAL_PARDON_SIGN, PRESIDENTIAL_PARDON_EXEC, "default target") { }
PresidentialPardonForm::PresidentialPardonForm(std::string const& target) : Form("PresidentialPardonform", PRESIDENTIAL_PARDON_SIGN, PRESIDENTIAL_PARDON_EXEC, target) { }
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) {
 	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm() { }
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
 	if ( this == &rhs ) { return *this; }
	this->setSigned(rhs.getSigned());
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (!getSigned()) { throw Form::NotSignedException(); }
	if (executor.getGrade() > getExecuteGrade()) { throw Form::GradeTooLowException(); }
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
