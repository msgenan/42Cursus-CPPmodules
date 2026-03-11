#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << BLUE << "║      Bureaucrat & Form Test        ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    // Test 1: Valid Form creation
    std::cout << BOLD << YELLOW << "▶ Test 1: Valid Form Creation" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        try
        {
            Form form1("Tax Form", 50, 25);
            std::cout << GREEN << form1 << RESET << std::endl;
            
            Form form2("Building Permit", 100, 50);
            std::cout << GREEN << form2 << RESET << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 2: Form grade too high exception
    std::cout << BOLD << YELLOW << "▶ Test 2: Form Grade Too High Exception" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        try
        {
            Form invalidForm("Invalid Form", 0, 50);
            std::cout << GREEN << invalidForm << RESET << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 3: Form grade too low exception
    std::cout << BOLD << YELLOW << "▶ Test 3: Form Grade Too Low Exception" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        try
        {
            Form invalidForm("Invalid Form", 50, 151);
            std::cout << GREEN << invalidForm << RESET << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 4: Successful form signing
    std::cout << BOLD << YELLOW << "▶ Test 4: Successful Form Signing" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        try
        {
            Bureaucrat alice("Alice", 30);
            Form form("Contract", 50, 25);
            
            std::cout << CYAN << "Before signing: " << form << RESET << std::endl;
            alice.signForm(form);
            std::cout << CYAN << "After signing:  " << form << RESET << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 5: Failed form signing (grade too low)
    std::cout << BOLD << YELLOW << "▶ Test 5: Failed Form Signing (Grade Too Low)" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        try
        {
            Bureaucrat bob("Bob", 100);
            Form form("Top Secret Document", 50, 25);
            
            std::cout << CYAN << "Before signing: " << form << RESET << std::endl;
            bob.signForm(form);
            std::cout << CYAN << "After signing:  " << form << RESET << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 6: Multiple bureaucrats signing forms
    std::cout << BOLD << YELLOW << "▶ Test 6: Multiple Bureaucrats Signing Forms" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        try
        {
            Bureaucrat ceo("CEO", 1);
            Bureaucrat manager("Manager", 50);
            Bureaucrat intern("Intern", 150);
            
            Form form1("Report", 100, 50);
            Form form2("Important Contract", 40, 20);
            Form form3("Presidential Order", 1, 1);
            
            std::cout << GREEN << ceo << RESET << std::endl;
            std::cout << GREEN << manager << RESET << std::endl;
            std::cout << GREEN << intern << RESET << std::endl;
            std::cout << std::endl;
            
            std::cout << CYAN << "Signing Report (grade 100 required):" << RESET << std::endl;
            intern.signForm(form1);
            manager.signForm(form1);
            std::cout << std::endl;
            
            std::cout << CYAN << "Signing Important Contract (grade 40 required):" << RESET << std::endl;
            manager.signForm(form2);
            ceo.signForm(form2);
            std::cout << std::endl;
            
            std::cout << CYAN << "Signing Presidential Order (grade 1 required):" << RESET << std::endl;
            manager.signForm(form3);
            ceo.signForm(form3);
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << BOLD << GREEN << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << GREEN << "║        All Tests Complete          ║" << RESET << std::endl;
    std::cout << BOLD << GREEN << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}
