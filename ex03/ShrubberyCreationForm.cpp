#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", SHRUBBERY_CREATION_SIGN, SHRUBBERY_CREATION_EXEC, "default target") { }
ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) : Form("ShrubberyCreationForm", SHRUBBERY_CREATION_SIGN, SHRUBBERY_CREATION_EXEC, target) { }
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) {
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm() { }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
 	if ( this == &rhs ) { return *this; }
	this->setSigned(rhs.getSigned());
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
