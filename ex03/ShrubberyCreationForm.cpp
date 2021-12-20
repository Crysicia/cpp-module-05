#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", SHRUBBERY_CREATION_SIGN, SHRUBBERY_CREATION_EXEC, "default target") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) : Form("ShrubberyCreationForm", SHRUBBERY_CREATION_SIGN, SHRUBBERY_CREATION_EXEC, target) {
	std::cout << "ShrubberyCreationForm named constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	std::cout << "ShrubberyCreationForm copy operator called" << std::endl;
	if ( this == &rhs ) { return *this; }
	*this = rhs;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (!getSigned()) { throw Form::NotSignedException(); }
	if (executor.getGrade() > getExecuteGrade()) { throw Form::GradeTooLowException(); }

	std::ofstream file((getTarget() + "_shruberry").c_str());
	if (!file.is_open()) { throw Form::CouldNotOpenFIleeException(); }
	file << "           .     .  .      +     .      .          ."				<< std::endl
		 << "     .       .      .     #       .           ."					<< std::endl
		 << "        .      .         ###            .      .      ."			<< std::endl
		 << "      .      .  \"#:. .:##\"##:. .:#\"  .      ."					<< std::endl
		 << "          .      . \"####\"###\"####\"  ."							<< std::endl
		 << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ."	<< std::endl
		 << "  .             \"#########\"#########\"        .        ." 		<< std::endl
		 << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ."		<< std::endl
		 << "     .     .  \"#######\"\"##\"##\"\"#######\"                  ." << std::endl
		 << "                .\"##\"#####\"#####\"##\"           .      ."		<< std::endl
		 << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ."			<< std::endl
		 << "      .     \"#######\"##\"#####\"##\"#######\"      .     ."		<< std::endl
		 << "    .    .     \"#####\"\"#######\"\"#####\"    .      ."			<< std::endl
		 << "            .     \"      000      \"    .     ."					<< std::endl
		 << "       .         .   .   000     .        .       ."				<< std::endl
		 << ".. .. ..................O000O........................ ......"		<< std::endl;
	file.close();
}
