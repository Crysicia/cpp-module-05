#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(std::string const& name);
	Bureaucrat(const Bureaucrat& copy);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& rhs);

	std::string const& getName(void) const;
	unsigned char& getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);

private:
	const std::string m_name;
	unsigned char m_grade;
};

#endif
