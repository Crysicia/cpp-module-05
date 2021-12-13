#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("Nameless") {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const& name) : m_name(name) {
	std::cout << "Bureaucrat named constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = copy;
	this->m_name = copy.m_name;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	std::cout << "Bureaucrat copy operator called" << std::endl;
	if ( this == &rhs ) { return *this; }
	this->m_name = rhs.m_name;
	return *this;
}

std::string const& Bureaucrat::getName(void) const {
	return m_name;
}

unsigned char const& Bureaucrat::getGrade(void) const {
	return m_grade;
}

std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
