#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(std::string const& name, unsigned char const& grade);
	Bureaucrat(const Bureaucrat& copy);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& rhs);

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

std::ostream& operator<< (std::ostream& os, const Bureaucrat& Bureaucrat);

#endif
