#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("Nameless"), m_grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const& name, unsigned char const& grade) : m_name(name) {
	std::cout << "Bureaucrat named constructor called" << std::endl;
	if (grade < 1 or grade > 150) {
		// throw error
		return ;
	}
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

unsigned char const& Bureaucrat::getGrade(void) const {
	return m_grade;
}

void Bureaucrat::incrementGrade(void) {
	if (m_grade > 1) {
		m_grade--;
	}
}

void Bureaucrat::decrementGrade(void) {
	if (m_grade < 150) {
		m_grade++;
	}
}

std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
