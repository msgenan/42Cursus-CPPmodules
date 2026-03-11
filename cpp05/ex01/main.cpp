#include "Bureaucrat.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << BLUE << "║          Bureaucrat Test           ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    // Test 1: Valid Bureaucrat creation
    std::cout << BOLD << YELLOW << "▶ Test 1: Valid Bureaucrat Creation" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        try
        {
            Bureaucrat bob("Bob", 75);
            std::cout << GREEN << bob << RESET << std::endl;
            
            Bureaucrat alice("Alice", 1);
            std::cout << GREEN << alice << RESET << std::endl;
            
            Bureaucrat john("John", 150);
            std::cout << GREEN << john << RESET << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 2: Grade too high exception
    std::cout << BOLD << YELLOW << "▶ Test 2: Grade Too High Exception" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        try
        {
            Bureaucrat invalid("Invalid", 0);
            std::cout << GREEN << invalid << RESET << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 3: Grade too low exception
    std::cout << BOLD << YELLOW << "▶ Test 3: Grade Too Low Exception" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        try
        {
            Bureaucrat invalid("Invalid", 151);
            std::cout << GREEN << invalid << RESET << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 4: Increment grade
    std::cout << BOLD << YELLOW << "▶ Test 4: Increment Grade" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        try
        {
            Bureaucrat worker("Worker", 3);
            std::cout << CYAN << worker << RESET << std::endl;
            
            worker.incrementGrade();
            std::cout << CYAN << "After increment: " << worker << RESET << std::endl;
            
            worker.incrementGrade();
            std::cout << CYAN << "After increment: " << worker << RESET << std::endl;
            
            std::cout << CYAN << "Trying to increment beyond limit..." << RESET << std::endl;
            worker.incrementGrade();
            std::cout << GREEN << worker << RESET << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 5: Decrement grade
    std::cout << BOLD << YELLOW << "▶ Test 5: Decrement Grade" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        try
        {
            Bureaucrat lazy("Lazy", 148);
            std::cout << CYAN << lazy << RESET << std::endl;
            
            lazy.decrementGrade();
            std::cout << CYAN << "After decrement: " << lazy << RESET << std::endl;
            
            lazy.decrementGrade();
            std::cout << CYAN << "After decrement: " << lazy << RESET << std::endl;
            
            std::cout << CYAN << "Trying to decrement beyond limit..." << RESET << std::endl;
            lazy.decrementGrade();
            std::cout << GREEN << lazy << RESET << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << BOLD << GREEN << "✓ All Tests Complete!" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}
