#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("Nameless"), m_grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const& name, int const& grade) : m_name(name) {
	std::cout << "Bureaucrat named constructor called" << std::endl;
	if (grade < 1 ) { throw Bureaucrat::GradeTooHighException(); }
	if (grade > 150 ) { throw Bureaucrat::GradeTooLowException(); }
	m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : m_name(copy.m_name),  m_grade(copy.m_grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	std::cout << "Bureaucrat copy operator called" << std::endl;
	if ( this == &rhs ) { return *this; }
	this->m_grade = rhs.m_grade;
	return *this;
}

void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
	} catch (std::exception& e) {
		std::cout << m_name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << m_name << " signs " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(Form const& form) {
	try {
		form.execute(*this);
	} catch (std::exception& e) {
		std::cout << m_name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << m_name << " executes " << form.getName() << std::endl;
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
