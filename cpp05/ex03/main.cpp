#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "╔════════════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << BLUE << "║             Intern Form Creation Test          ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "╚════════════════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    // Test 1: Create ShrubberyCreationForm through Intern
    std::cout << BOLD << YELLOW << "▶ Test 1: Intern Creates ShrubberyCreationForm" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            Intern intern;
            AForm* form = intern.makeForm("shrubbery creation", "garden");
            
            if (form != NULL)
            {
                std::cout << GREEN << "Form created: " << form->getName() << RESET << std::endl;
                std::cout << GREEN << *form << RESET << std::endl;
                
                Bureaucrat bureaucrat("Alice", 137);
                bureaucrat.signForm(*form);
                bureaucrat.executeForm(*form);
                
                delete form;
                std::cout << GREEN << "✓ Form executed and deleted successfully!" << RESET << std::endl;
            }
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 2: Create RobotomyRequestForm through Intern
    std::cout << BOLD << YELLOW << "▶ Test 2: Intern Creates RobotomyRequestForm" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            Intern intern;
            AForm* form = intern.makeForm("robotomy request", "Marvin");
            
            if (form != NULL)
            {
                std::cout << GREEN << "Form created: " << form->getName() << RESET << std::endl;
                std::cout << GREEN << *form << RESET << std::endl;
                
                Bureaucrat bureaucrat("Bob", 45);
                bureaucrat.signForm(*form);
                
                std::cout << CYAN << "Executing form (50% success rate):" << RESET << std::endl;
                for (int i = 0; i < 3; i++)
                {
                    bureaucrat.executeForm(*form);
                    std::cout << std::endl;
                }
                
                delete form;
                std::cout << GREEN << "✓ Form executed and deleted successfully!" << RESET << std::endl;
            }
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 3: Create PresidentialPardonForm through Intern
    std::cout << BOLD << YELLOW << "▶ Test 3: Intern Creates PresidentialPardonForm" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            Intern intern;
            AForm* form = intern.makeForm("presidential pardon", "Zaphod");
            
            if (form != NULL)
            {
                std::cout << GREEN << "Form created: " << form->getName() << RESET << std::endl;
                std::cout << GREEN << *form << RESET << std::endl;
                
                Bureaucrat bureaucrat("Charlie", 5);
                bureaucrat.signForm(*form);
                bureaucrat.executeForm(*form);
                
                delete form;
                std::cout << GREEN << "✓ Form executed and deleted successfully!" << RESET << std::endl;
            }
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 4: Invalid form name
    std::cout << BOLD << YELLOW << "▶ Test 4: Intern with Invalid Form Name" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            Intern intern;
            std::cout << CYAN << "Attempting to create invalid form 'tax form':" << RESET << std::endl;
            AForm* form = intern.makeForm("tax form", "target");
            
            if (form == NULL)
            {
                std::cout << GREEN << "✓ Correctly returned NULL for invalid form" << RESET << std::endl;
            }
            else
            {
                delete form;
            }
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 5: Multiple interns creating forms
    std::cout << BOLD << YELLOW << "▶ Test 5: Multiple Interns Creating Forms" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            std::cout << CYAN << "Creating three interns to make different forms:" << RESET << std::endl;
            
            Intern intern1;
            AForm* form1 = intern1.makeForm("shrubbery creation", "park");
            
            Intern intern2;
            AForm* form2 = intern2.makeForm("robotomy request", "target");
            
            Intern intern3;
            AForm* form3 = intern3.makeForm("presidential pardon", "prisoner");
            
            std::cout << std::endl;
            if (form1 && form2 && form3)
            {
                std::cout << GREEN << "✓ All three forms created successfully!" << RESET << std::endl;
                std::cout << GREEN << "Form 1: " << form1->getName() << RESET << std::endl;
                std::cout << GREEN << "Form 2: " << form2->getName() << RESET << std::endl;
                std::cout << GREEN << "Form 3: " << form3->getName() << RESET << std::endl;
                
                delete form1;
                delete form2;
                delete form3;
            }
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 6: Form with different target names
    std::cout << BOLD << YELLOW << "▶ Test 6: Forms with Various Target Names" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            Intern intern;
            
            std::string targets[4] = {"Alice", "Bob", "home", "office"};
            
            for (int i = 0; i < 4; i++)
            {
                AForm* form = intern.makeForm("shrubbery creation", targets[i]);
                if (form != NULL)
                {
                    std::cout << GREEN << "Created ShrubberyCreationForm for target: " << targets[i] << RESET << std::endl;
                    delete form;
                }
            }
            
            std::cout << GREEN << "✓ All forms with different targets created successfully!" << RESET << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 7: Complete workflow with Intern
    std::cout << BOLD << YELLOW << "▶ Test 7: Complete Workflow (Intern → Form → Sign → Execute)" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            std::cout << CYAN << "Step 1: Creating intern" << RESET << std::endl;
            Intern intern;
            
            std::cout << CYAN << "Step 2: Creating celebrity pardon form" << RESET << std::endl;
            AForm* form = intern.makeForm("presidential pardon", "Captain Kirk");
            
            std::cout << CYAN << "Step 3: Creating bureaucrat with sufficient grades" << RESET << std::endl;
            Bureaucrat manager("Manager", 5);
            
            std::cout << CYAN << "Step 4: Signing form" << RESET << std::endl;
            manager.signForm(*form);
            
            std::cout << CYAN << "Step 5: Executing form" << RESET << std::endl;
            manager.executeForm(*form);
            
            std::cout << std::endl;
            std::cout << GREEN << "✓ Complete workflow executed successfully!" << RESET << std::endl;
            
            delete form;
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
