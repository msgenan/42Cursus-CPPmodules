#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) 
{
    if (this != &other)
        this->_target = other._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
    std::string filename = this->_target + "_shrubbery";
    std::ofstream outFile(filename.c_str());
    if (!outFile.is_open())
        throw ShrubberyCreationForm::FileOpenException();

    outFile << "               ,@@@@@@@," << std::endl;
    outFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    outFile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
    outFile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    outFile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    outFile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
    outFile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    outFile << "       |o|        | |         | |" << std::endl;
    outFile << "       |.|        | |         | |" << std::endl;
    outFile << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;

    outFile.close();
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw() {
    return "Error: Could not create or open the shrubbery file!";
}
