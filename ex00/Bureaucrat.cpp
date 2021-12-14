#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("Nameless"), m_grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const& name, unsigned char const& grade) : m_name(name) {
	std::cout << "Bureaucrat named constructor called" << std::endl;
	if (grade < 1 ) { throw Bureaucrat::GradeTooHighException(); }
	if (grade > 150 ) { throw Bureaucrat::GradeTooLowException(); }
	m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = copy;
	// TO ASK: Could I assign a const ?
	// this->m_name = copy.m_name;
	this->m_grade = copy.m_grade;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	std::cout << "Bureaucrat copy operator called" << std::endl;
	if ( this == &rhs ) { return *this; }
	// TO ASK: Could I assign a const ?
	// this->m_name = rhs.m_name;
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
	m_grade--;
	if (m_grade < 1 ) { throw Bureaucrat::GradeTooHighException(); }
}

void Bureaucrat::decrementGrade(void) {
	m_grade++;
	if (m_grade > 150 ) { throw Bureaucrat::GradeTooLowException(); }
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
