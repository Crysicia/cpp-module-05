#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define ROBOROMY_REQUEST_SIGN 72
#define ROBOROMY_REQUEST_EXEC 45

class Bureaucrat;
class RobotomyRequestForm : public Form {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const& target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

	void execute(Bureaucrat const& executor) const;
};

#endif
