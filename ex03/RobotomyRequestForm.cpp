#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", ROBOROMY_REQUEST_SIGN, ROBOROMY_REQUEST_EXEC, "default target") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) : Form("RobotomyRequestForm", ROBOROMY_REQUEST_SIGN, ROBOROMY_REQUEST_EXEC, target) {
	std::cout << "RobotomyRequestForm named constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	std::cout << "RobotomyRequestForm copy operator called" << std::endl;
	if ( this == &rhs ) { return *this; }
	// this->m_signed = rhs.m_signed;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (!getSigned()) { throw Form::NotSignedException(); }
	if (executor.getGrade() > getExecuteGrade()) { throw Form::GradeTooLowException(); }
	srand(time(0));

	if (rand() % 2) {
		std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomization FAILED!" << std::endl;
	}
}