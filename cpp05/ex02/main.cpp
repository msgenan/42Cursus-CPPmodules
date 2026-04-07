#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "╔════════════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << BLUE << "║    Bureaucrat & Abstract Form Test (AForm)     ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "╚════════════════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    // Test 1: ShrubberyCreationForm
    std::cout << BOLD << YELLOW << "▶ Test 1: ShrubberyCreationForm" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            Bureaucrat alice("Alice", 140);
            ShrubberyCreationForm shrub("garden");
            
            std::cout << GREEN << alice << RESET << std::endl;
            std::cout << GREEN << shrub << RESET << std::endl;
            std::cout << std::endl;
            
            std::cout << CYAN << "Attempting to execute unsigned form:" << RESET << std::endl;
            alice.executeForm(shrub);
            std::cout << std::endl;
            
            std::cout << CYAN << "Signing the form:" << RESET << std::endl;
            alice.signForm(shrub);
            std::cout << std::endl;
            
            std::cout << CYAN << "Attempting to execute with insufficient grade:" << RESET << std::endl;
            alice.executeForm(shrub);
            std::cout << std::endl;
            
            std::cout << CYAN << "Creating bureaucrat with sufficient grade (Bob - grade 137):" << RESET << std::endl;
            Bureaucrat bob("Bob", 137);
            bob.executeForm(shrub);
            std::cout << GREEN << "✓ File 'garden_shrubbery' created successfully!" << RESET << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 2: RobotomyRequestForm
    std::cout << BOLD << YELLOW << "▶ Test 2: RobotomyRequestForm" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            Bureaucrat charlie("Charlie", 45);
            RobotomyRequestForm robot("Alice");
            
            std::cout << GREEN << charlie << RESET << std::endl;
            std::cout << GREEN << robot << RESET << std::endl;
            std::cout << std::endl;
            
            std::cout << CYAN << "Signing the form:" << RESET << std::endl;
            charlie.signForm(robot);
            std::cout << std::endl;
            
            std::cout << CYAN << "Executing robotomy form (multiple executions - 50% success rate):" << RESET << std::endl;
            for (int i = 0; i < 4; i++)
            {
                std::cout << YELLOW << "[Execution " << (i + 1) << "]" << RESET << std::endl;
                charlie.executeForm(robot);
                std::cout << std::endl;
            }
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 3: PresidentialPardonForm
    std::cout << BOLD << YELLOW << "▶ Test 3: PresidentialPardonForm" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            Bureaucrat dave("Dave", 5);
            PresidentialPardonForm pardon("Criminal");
            
            std::cout << GREEN << dave << RESET << std::endl;
            std::cout << GREEN << pardon << RESET << std::endl;
            std::cout << std::endl;
            
            std::cout << CYAN << "Attempting to execute unsigned form:" << RESET << std::endl;
            dave.executeForm(pardon);
            std::cout << std::endl;
            
            std::cout << CYAN << "Signing and executing:" << RESET << std::endl;
            dave.signForm(pardon);
            dave.executeForm(pardon);
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 4: Grade too low to sign ShrubberyCreationForm
    std::cout << BOLD << YELLOW << "▶ Test 4: Grade Too Low to Sign" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            Bureaucrat eve("Eve", 150);
            ShrubberyCreationForm shrub("backyard");
            
            std::cout << GREEN << eve << RESET << std::endl;
            std::cout << GREEN << shrub << RESET << std::endl;
            std::cout << std::endl;
            
            std::cout << CYAN << "Eve (grade 150) attempting to sign (requires grade 145):" << RESET << std::endl;
            eve.signForm(shrub);
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 5: Grade too low to execute RobotomyRequestForm
    std::cout << BOLD << YELLOW << "▶ Test 5: Grade Too Low to Execute" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            Bureaucrat frank("Frank", 50);
            RobotomyRequestForm robot("Subject");
            
            std::cout << GREEN << frank << RESET << std::endl;
            std::cout << GREEN << robot << RESET << std::endl;
            std::cout << std::endl;
            
            std::cout << CYAN << "George (grade 72) signing robotomy form:" << RESET << std::endl;
            Bureaucrat george("George", 72);
            george.signForm(robot);
            std::cout << std::endl;
            
            std::cout << CYAN << "Frank (grade 50) attempting to execute (requires grade 45):" << RESET << std::endl;
            frank.executeForm(robot);
            std::cout << std::endl;
            
            std::cout << CYAN << "Grace (grade 45) executing robotomy form:" << RESET << std::endl;
            Bureaucrat grace("Grace", 45);
            grace.executeForm(robot);
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 6: Valid execution chain with PresidentialPardonForm
    std::cout << BOLD << YELLOW << "▶ Test 6: Valid Execution Chain" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            Bureaucrat henry("Henry", 25);
            PresidentialPardonForm pardon("President");
            
            std::cout << GREEN << henry << RESET << std::endl;
            std::cout << GREEN << pardon << RESET << std::endl;
            std::cout << std::endl;
            
            std::cout << CYAN << "Henry (grade 25) signing pardon form (requires grade 25):" << RESET << std::endl;
            henry.signForm(pardon);
            std::cout << std::endl;
            
            std::cout << CYAN << "Henry (grade 25) attempting to execute (requires grade 5):" << RESET << std::endl;
            henry.executeForm(pardon);
            std::cout << std::endl;
            
            std::cout << CYAN << "Ivan (grade 5) executing pardon form:" << RESET << std::endl;
            Bureaucrat ivan("Ivan", 5);
            ivan.executeForm(pardon);
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 7: All forms together
    std::cout << BOLD << YELLOW << "▶ Test 7: All Forms Together (Complete Workflow)" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            std::cout << CYAN << "Creating the President (grade 1 - can do everything):" << RESET << std::endl;
            Bureaucrat president("President", 1);
            std::cout << GREEN << president << RESET << std::endl;
            std::cout << std::endl;
            
            std::cout << CYAN << "Creating all forms:" << RESET << std::endl;
            ShrubberyCreationForm shrub("Park");
            RobotomyRequestForm robot("Intruder");
            PresidentialPardonForm pardon("Villain");
            std::cout << GREEN << shrub << RESET << std::endl;
            std::cout << GREEN << robot << RESET << std::endl;
            std::cout << GREEN << pardon << RESET << std::endl;
            std::cout << std::endl;
            
            std::cout << CYAN << "President signing and executing all forms:" << RESET << std::endl;
            president.signForm(shrub);
            president.executeForm(shrub);
            std::cout << std::endl;
            
            president.signForm(robot);
            president.executeForm(robot);
            std::cout << std::endl;
            
            president.signForm(pardon);
            president.executeForm(pardon);
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << BOLD << GREEN << "╔════════════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << GREEN << "║            All Tests Complete! ✓               ║" << RESET << std::endl;
    std::cout << BOLD << GREEN << "╚════════════════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}
