#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
public:
	Form();
	Form(std::string const& name, int const& sign_grade, int const& execute_grade);
	Form(const Form& copy);
	~Form();
	Form& operator=(const Form& rhs);

	void beSigned(Bureaucrat& bureaucrat);
	std::string const& getName(void) const;
	bool const& getSigned(void) const;
	int const& getSignGrade(void) const;
	int const& getExecuteGrade(void) const;

	class GradeTooLowException : public std::exception {
		const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
		const char* what() const throw();
	};

private:
	const std::string m_name;
	bool m_signed;
	const int m_sign_grade;
	const int m_execute_grade;
};

std::ostream& operator<< (std::ostream& os, const Form& form);

#endif
