#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <iomanip>

// Color codes
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define CYAN        "\033[36m"

int main()
{
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "╔════════════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << BLUE << "║          Serializer Test Suite (ex01)          ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "╚════════════════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    // Test 1: Basic Serialize/Deserialize
    std::cout << BOLD << YELLOW << "▶ Test 1: Basic Serialize/Deserialize" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            Data* original = new Data(42, "John Doe", "Admin");
            
            std::cout << CYAN << "Original Data:" << RESET << std::endl;
            std::cout << "  ID: " << original->id << std::endl;
            std::cout << "  Name: " << original->name << std::endl;
            std::cout << "  Type: " << original->type << std::endl;
            std::cout << "  Address: " << std::hex << reinterpret_cast<uintptr_t>(original) << std::dec << std::endl;
            
            std::cout << std::endl << CYAN << "Serializing..." << RESET << std::endl;
            uintptr_t serialized = Serializer::serialize(original);
            std::cout << GREEN << "Serialized value: " << std::hex << serialized << std::dec << RESET << std::endl;
            
            std::cout << std::endl << CYAN << "Deserializing..." << RESET << std::endl;
            Data* deserialized = Serializer::deserialize(serialized);
            
            std::cout << GREEN << "Deserialized Data:" << RESET << std::endl;
            std::cout << "  ID: " << deserialized->id << std::endl;
            std::cout << "  Name: " << deserialized->name << std::endl;
            std::cout << "  Type: " << deserialized->type << std::endl;
            std::cout << "  Address: " << std::hex << reinterpret_cast<uintptr_t>(deserialized) << std::dec << std::endl;
            
            std::cout << std::endl;
            if (deserialized == original && 
                deserialized->id == original->id && 
                deserialized->name == original->name && 
                deserialized->type == original->type)
            {
                std::cout << GREEN << "✓ Serialize/Deserialize works correctly!" << RESET << std::endl;
                std::cout << GREEN << "✓ Pointer identity preserved!" << RESET << std::endl;
            }
            else
                std::cout << RED << "✗ Mismatch detected!" << RESET << std::endl;
            
            delete original;
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 2: Multiple Objects
    std::cout << BOLD << YELLOW << "▶ Test 2: Multiple Data Objects" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            Data* data1 = new Data(1, "Alice", "User");
            Data* data2 = new Data(2, "Bob", "Admin");
            Data* data3 = new Data(3, "Charlie", "Guest");
            
            std::cout << CYAN << "Creating 3 different Data objects..." << RESET << std::endl;
            
            uintptr_t raw1 = Serializer::serialize(data1);
            uintptr_t raw2 = Serializer::serialize(data2);
            uintptr_t raw3 = Serializer::serialize(data3);
            
            std::cout << GREEN << "Serialized all objects" << RESET << std::endl;
            
            Data* restored1 = Serializer::deserialize(raw1);
            Data* restored2 = Serializer::deserialize(raw2);
            Data* restored3 = Serializer::deserialize(raw3);
            
            std::cout << std::endl;
            std::cout << "Verification:" << std::endl;
            std::cout << "  Object 1: " << (restored1 == data1 ? GREEN "✓" RESET : RED "✗" RESET) 
                      << " " << restored1->name << " (" << restored1->type << ")" << std::endl;
            std::cout << "  Object 2: " << (restored2 == data2 ? GREEN "✓" RESET : RED "✗" RESET) 
                      << " " << restored2->name << " (" << restored2->type << ")" << std::endl;
            std::cout << "  Object 3: " << (restored3 == data3 ? GREEN "✓" RESET : RED "✗" RESET) 
                      << " " << restored3->name << " (" << restored3->type << ")" << std::endl;
            
            std::cout << std::endl;
            if (restored1 == data1 && restored2 == data2 && restored3 == data3)
                std::cout << GREEN << "✓ All objects correctly serialized and deserialized!" << RESET << std::endl;
            
            delete data1;
            delete data2;
            delete data3;
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 3: Empty/Default Data
    std::cout << BOLD << YELLOW << "▶ Test 3: Default Constructor Data" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            Data* data = new Data();
            
            std::cout << CYAN << "Created Data with default constructor:" << RESET << std::endl;
            std::cout << "  ID: " << data->id << std::endl;
            std::cout << "  Name: " << data->name << std::endl;
            std::cout << "  Type: " << data->type << std::endl;
            
            uintptr_t raw = Serializer::serialize(data);
            Data* restored = Serializer::deserialize(raw);
            
            std::cout << std::endl;
            if (restored == data)
                std::cout << GREEN << "✓ Default Data object correctly serialized!" << RESET << std::endl;
            
            delete data;
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 4: Data with Special Characters
    std::cout << BOLD << YELLOW << "▶ Test 4: Data with Special Characters" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            Data* data = new Data(999, "User@Host#2024!!", "Type-Admin_Manager");
            
            std::cout << CYAN << "Original Data:" << RESET << std::endl;
            std::cout << "  ID: " << data->id << std::endl;
            std::cout << "  Name: " << data->name << std::endl;
            std::cout << "  Type: " << data->type << std::endl;
            
            uintptr_t raw = Serializer::serialize(data);
            Data* restored = Serializer::deserialize(raw);
            
            std::cout << std::endl << CYAN << "Restored Data:" << RESET << std::endl;
            std::cout << "  ID: " << restored->id << std::endl;
            std::cout << "  Name: " << restored->name << std::endl;
            std::cout << "  Type: " << restored->type << std::endl;
            
            std::cout << std::endl;
            if (restored == data && 
                restored->id == data->id && 
                restored->name == data->name && 
                restored->type == data->type)
            {
                std::cout << GREEN << "✓ Special characters preserved correctly!" << RESET << std::endl;
            }
            
            delete data;
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 5: Sequential Serialization
    std::cout << BOLD << YELLOW << "▶ Test 5: Sequential Serialization/Deserialization" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            Data* data = new Data(777, "Sequential Test", "Process");
            
            std::cout << CYAN << "Testing multiple serialize/deserialize cycles:" << RESET << std::endl;
            
            for (int i = 1; i <= 3; i++)
            {
                uintptr_t raw = Serializer::serialize(data);
                Data* restored = Serializer::deserialize(raw);
                
                if (restored == data)
                    std::cout << "  Cycle " << i << ": " << GREEN "✓" RESET << " Success" << std::endl;
                else
                    std::cout << "  Cycle " << i << ": " << RED "✗" RESET << " Failed" << std::endl;
            }
            
            delete data;
            std::cout << std::endl << GREEN << "✓ All sequential cycles completed!" << RESET << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // Test 6: Large ID Values
    std::cout << BOLD << YELLOW << "▶ Test 6: Large ID Values" << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    {
        try
        {
            int large_ids[] = {2147483647, 0, -1, 1000000};
            std::cout << CYAN << "Testing with large ID values:" << RESET << std::endl;
            
            for (int i = 0; i < 4; i++)
            {
                Data* data = new Data(large_ids[i], "Test", "Value");
                
                uintptr_t raw = Serializer::serialize(data);
                Data* restored = Serializer::deserialize(raw);
                
                if (restored->id == data->id)
                    std::cout << "  ID " << std::setw(12) << large_ids[i] << ": " << GREEN "✓" RESET << std::endl;
                else
                    std::cout << "  ID " << std::setw(12) << large_ids[i] << ": " << RED "✗" RESET << std::endl;
                
                delete data;
            }
            
            std::cout << std::endl << GREEN << "✓ All ID values preserved correctly!" << RESET << std::endl;
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
