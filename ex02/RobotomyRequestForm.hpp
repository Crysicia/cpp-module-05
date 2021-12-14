#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;
class RobotomyRequestForm : public Form {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const& target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
};

#endif
