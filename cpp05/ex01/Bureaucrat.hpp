#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define RESET  "\033[0m"
#define BOLD   "\033[1m"
#define RED    "\033[31m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"
#define BLUE   "\033[34m"
#define CYAN   "\033[36m"

class Form;

class Bureaucrat
{
private:
    const std::string   _name;
    int                 _grade;

public:
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string&  getName() const;
    int                 getGrade() const;

    void    incrementGrade();
    void    decrementGrade();

    void    signForm(Form& form);

    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif