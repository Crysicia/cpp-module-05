#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("Nameless"), m_grade(150) { }
Bureaucrat::Bureaucrat(std::string const& name, int const& grade) : m_name(name) {
 	if (grade < 1 ) { throw Bureaucrat::GradeTooHighException(); }
	if (grade > 150 ) { throw Bureaucrat::GradeTooLowException(); }
	m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : m_name(copy.m_name), m_grade(copy.m_grade) {
 	*this = copy;
}

Bureaucrat::~Bureaucrat() { }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
 	if ( this == &rhs ) { return *this; }
 	const_cast<std::string&>(this->m_name) = rhs.m_name;
	this->m_grade = rhs.m_grade;
	return *this;
}

std::string const& Bureaucrat::getName(void) const {
	return m_name;
}

int const& Bureaucrat::getGrade(void) const {
	return m_grade;
}

void Bureaucrat::incrementGrade(void) {
	if (m_grade == 1 ) { throw Bureaucrat::GradeTooHighException(); }
	m_grade--;
}

void Bureaucrat::decrementGrade(void) {
	if (m_grade == 150 ) { throw Bureaucrat::GradeTooLowException(); }
	m_grade++;
}

std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}
