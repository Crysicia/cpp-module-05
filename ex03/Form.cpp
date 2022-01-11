#include "Form.hpp"

Form::Form() : m_name("Untitled form"), m_target("no target"), m_signed(false), m_sign_grade(150), m_execute_grade(150) { }

Form::Form(std::string const& name, int const& sign_grade, int const& execute_grade) : m_name(name), m_target("no target"), m_signed(false), m_sign_grade(sign_grade), m_execute_grade(execute_grade) {
 	if (sign_grade < 1 or execute_grade < 1) { throw Form::GradeTooHighException(); }
	if (sign_grade > 150 or execute_grade > 150) { throw Form::GradeTooLowException(); }
}

Form::Form(std::string const& name, int const& sign_grade, int const& execute_grade, std::string const& target) : m_name(name), m_target(target), m_signed(false), m_sign_grade(sign_grade), m_execute_grade(execute_grade) {
 	if (sign_grade < 1 or execute_grade < 1) { throw Form::GradeTooHighException(); }
	if (sign_grade > 150 or execute_grade > 150) { throw Form::GradeTooLowException(); }
}

Form::Form(const Form& copy) : m_name(copy.m_name), m_target(copy.m_target), m_signed(copy.m_signed), m_sign_grade(copy.m_sign_grade), m_execute_grade(copy.m_execute_grade) {
 	*this = copy;
}

Form::~Form() { }

Form& Form::operator=(const Form& rhs) {
	if ( this == &rhs ) { return *this; }
	const_cast<std::string&>(this->m_name) = rhs.m_name;
	const_cast<std::string&>(this->m_target) = rhs.m_target;
	const_cast<int&>(this->m_sign_grade) = rhs.m_sign_grade;
	const_cast<int&>(this->m_execute_grade) = rhs.m_execute_grade;
	this->m_signed = rhs.m_signed;
	return *this;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > m_sign_grade) { throw Form::GradeTooLowException(); }
	m_signed = true;
}

std::string const& Form::getName(void) const {
	return m_name;
}

std::string const& Form::getTarget(void) const {
	return m_target;
}

bool const& Form::getSigned(void) const {
	return m_signed;
}

void Form::setSigned(bool value) {
	this->m_signed = value;
}

int const& Form::getSignGrade(void) const {
	return m_sign_grade;
}

int const& Form::getExecuteGrade(void) const {
	return m_execute_grade;
}

std::ostream& operator<< (std::ostream& os, const Form& form) {
	os << form.getName() << ", form execute grade: " << form.getExecuteGrade() << ", form sign grade: " << form.getSignGrade() << ", form is signed: " << form.getSigned();
	return os;
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Form::NotSignedException::what() const throw() {
	return "Form not signed";
}

const char* Form::CouldNotOpenFIleeException::what() const throw() {
	return "COuld not open file";
}
