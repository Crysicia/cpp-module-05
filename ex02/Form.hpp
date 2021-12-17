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
	Form(std::string const& name, int const& sign_grade, int const& execute_grade, std::string const& target);
	Form(const Form& copy);
	virtual	~Form();
	Form& operator=(const Form& rhs);

	void beSigned(Bureaucrat& bureaucrat);
	std::string const& getName(void) const;
	std::string const& getTarget(void) const;
	bool const& getSigned(void) const;
	int const& getSignGrade(void) const;
	int const& getExecuteGrade(void) const;
	virtual void execute(Bureaucrat const& executor) const = 0;

	class GradeTooLowException : public std::exception {
		const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
		const char* what() const throw();
	};

	class NotSignedException : public std::exception {
		const char* what() const throw();
	};

	class CouldNotOpenFIleeException : public std::exception {
		const char* what() const throw();
	};

private:
	const std::string m_name;
	const std::string m_target;
	bool m_signed;
	const int m_sign_grade;
	const int m_execute_grade;
};

std::ostream& operator<< (std::ostream& os, const Form& form);

#endif
