#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", ROBOROMY_REQUEST_SIGN, ROBOROMY_REQUEST_EXEC, "default target") { }
RobotomyRequestForm::RobotomyRequestForm(std::string const& target) : Form("RobotomyRequestForm", ROBOROMY_REQUEST_SIGN, ROBOROMY_REQUEST_EXEC, target) { }
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) {
 	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm() { }
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
 	if ( this == &rhs ) { return *this; }
	this->setSigned(rhs.getSigned());
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
