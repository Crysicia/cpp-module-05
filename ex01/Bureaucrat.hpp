#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;
class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(std::string const& name, int const& grade);
	Bureaucrat(const Bureaucrat& copy);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& rhs);


	void signForm(Form& form);
	std::string const& getName(void) const;
	int const& getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);

	class GradeTooLowException : public std::exception {
		const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
		const char* what() const throw();
	};

private:
	const std::string m_name;
	int m_grade;
};

std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat);

#endif
