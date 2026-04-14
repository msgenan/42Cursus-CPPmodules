#include "Array.hpp"

// Color codes
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

int main() {
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << BLUE << "║      Array Template Class          ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    // Test 1: Empty array construction
    std::cout << BOLD << YELLOW << "▶ Test 1: Empty Array Construction" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        Array<int> emptyArray;
        std::cout << CYAN << "Empty array size: " << RESET << emptyArray.size() << std::endl;
    }
    std::cout << std::endl;

    // Test 2: Array with specific size
    std::cout << BOLD << YELLOW << "▶ Test 2: Array With Specific Size" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        Array<int> intArray(5);
        std::cout << CYAN << "Array size: " << RESET << intArray.size() << std::endl;
        std::cout << GREEN << "Initial values: " << RESET;
        for (unsigned int i = 0; i < intArray.size(); i++)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Test 3: Fill array with values and access
    std::cout << BOLD << YELLOW << "▶ Test 3: Fill Array With Values" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        Array<int> intArray(5);
        std::cout << CYAN << "Filling array with values: " << RESET << std::endl;
        for (unsigned int i = 0; i < intArray.size(); i++)
            intArray[i] = (i + 1) * 10;
        
        std::cout << GREEN << "Array contents: " << RESET;
        for (unsigned int i = 0; i < intArray.size(); i++)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Test 4: String array
    std::cout << BOLD << YELLOW << "▶ Test 4: String Array" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        Array<std::string> strArray(4);
        strArray[0] = "Hello";
        strArray[1] = "World";
        strArray[2] = "Template";
        strArray[3] = "Array";
        
        std::cout << GREEN << "String array: " << RESET;
        for (unsigned int i = 0; i < strArray.size(); i++)
            std::cout << strArray[i] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Test 5: Copy constructor
    std::cout << BOLD << YELLOW << "▶ Test 5: Copy Constructor" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        Array<int> original(3);
        original[0] = 100;
        original[1] = 200;
        original[2] = 300;
        
        Array<int> copy(original);
        
        std::cout << CYAN << "Original array: " << RESET;
        for (unsigned int i = 0; i < original.size(); i++)
            std::cout << original[i] << " ";
        std::cout << std::endl;
        
        std::cout << CYAN << "Copied array:   " << RESET;
        for (unsigned int i = 0; i < copy.size(); i++)
            std::cout << copy[i] << " ";
        std::cout << std::endl;
        
        // Modify copy
        copy[0] = 999;
        std::cout << MAGENTA << "After modifying copy[0] to 999:" << RESET << std::endl;
        std::cout << CYAN << "Original array: " << RESET;
        for (unsigned int i = 0; i < original.size(); i++)
            std::cout << original[i] << " ";
        std::cout << std::endl;
        
        std::cout << CYAN << "Copied array:   " << RESET;
        for (unsigned int i = 0; i < copy.size(); i++)
            std::cout << copy[i] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Test 6: Assignment operator
    std::cout << BOLD << YELLOW << "▶ Test 6: Assignment Operator" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        Array<int> source(3);
        source[0] = 11;
        source[1] = 22;
        source[2] = 33;
        
        Array<int> destination(5);
        destination[0] = 1;
        destination[1] = 2;
        destination[2] = 3;
        destination[3] = 4;
        destination[4] = 5;
        
        std::cout << CYAN << "Before assignment:" << RESET << std::endl;
        std::cout << "  Source size: " << source.size() << ", values: ";
        for (unsigned int i = 0; i < source.size(); i++)
            std::cout << source[i] << " ";
        std::cout << std::endl;
        
        std::cout << "  Destination size: " << destination.size() << ", values: ";
        for (unsigned int i = 0; i < destination.size(); i++)
            std::cout << destination[i] << " ";
        std::cout << std::endl;
        
        destination = source;
        
        std::cout << MAGENTA << "After assignment:" << RESET << std::endl;
        std::cout << "  Destination size: " << destination.size() << ", values: ";
        for (unsigned int i = 0; i < destination.size(); i++)
            std::cout << destination[i] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Test 7: Out of bounds exception
    std::cout << BOLD << YELLOW << "▶ Test 7: Out of Bounds Exception" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        Array<int> arr(3);
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        
        std::cout << CYAN << "Array size: " << RESET << arr.size() << std::endl;
        std::cout << GREEN << "Valid access - arr[2]: " << RESET << arr[2] << std::endl;
        
        try
        {
            std::cout << CYAN << "Attempting invalid access - arr[5]..." << RESET << std::endl;
            std::cout << arr[5];
        }
        catch (const std::exception& e)
        {
            std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 8: Double array
    std::cout << BOLD << YELLOW << "▶ Test 8: Double Array" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        Array<double> doubleArr(4);
        doubleArr[0] = 1.1;
        doubleArr[1] = 2.2;
        doubleArr[2] = 3.3;
        doubleArr[3] = 4.4;
        
        std::cout << GREEN << "Double array: " << RESET;
        for (unsigned int i = 0; i < doubleArr.size(); i++)
            std::cout << doubleArr[i] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Test 9: Const array access
    std::cout << BOLD << YELLOW << "▶ Test 9: Const Array Access" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        Array<int> arr(3);
        arr[0] = 100;
        arr[1] = 200;
        arr[2] = 300;
        
        const Array<int>& constRef = arr;
        std::cout << GREEN << "Const array access: " << RESET;
        for (unsigned int i = 0; i < constRef.size(); i++)
            std::cout << constRef[i] << " ";
        std::cout << std::endl;
        
        try
        {
            std::cout << CYAN << "Attempting invalid const access - arr[10]..." << RESET << std::endl;
            std::cout << constRef[10];
        }
        catch (const std::exception& e)
        {
            std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 10: Multiple assignments chained
    std::cout << BOLD << YELLOW << "▶ Test 10: Multiple Assignments Chained" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        Array<int> arr1(3);
        Array<int> arr2(3);
        Array<int> arr3(3);
        
        arr1[0] = 11; arr1[1] = 22; arr1[2] = 33;
        arr2[0] = 44; arr2[1] = 55; arr2[2] = 66;
        arr3[0] = 77; arr3[1] = 88; arr3[2] = 99;
        
        std::cout << CYAN << "Before chained assignment:" << RESET << std::endl;
        std::cout << "  arr1: "; for (unsigned int i = 0; i < arr1.size(); i++) std::cout << arr1[i] << " "; std::cout << std::endl;
        std::cout << "  arr2: "; for (unsigned int i = 0; i < arr2.size(); i++) std::cout << arr2[i] << " "; std::cout << std::endl;
        std::cout << "  arr3: "; for (unsigned int i = 0; i < arr3.size(); i++) std::cout << arr3[i] << " "; std::cout << std::endl;
        
        std::cout << MAGENTA << "Performing: arr1 = arr2 = arr3" << RESET << std::endl;
        arr1 = arr2 = arr3;
        
        std::cout << CYAN << "After chained assignment:" << RESET << std::endl;
        std::cout << "  arr1: "; for (unsigned int i = 0; i < arr1.size(); i++) std::cout << arr1[i] << " "; std::cout << std::endl;
        std::cout << "  arr2: "; for (unsigned int i = 0; i < arr2.size(); i++) std::cout << arr2[i] << " "; std::cout << std::endl;
        std::cout << "  arr3: "; for (unsigned int i = 0; i < arr3.size(); i++) std::cout << arr3[i] << " "; std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << BOLD << GREEN << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << GREEN << "║        All Tests Complete          ║" << RESET << std::endl;
    std::cout << BOLD << GREEN << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}
