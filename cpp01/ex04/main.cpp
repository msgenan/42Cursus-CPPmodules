#include "replace.hpp"

static int print_error(std::string message)
{
    std::cerr << BOLD << RED << "Error: " << RESET << message << std::endl;
    return (1);
}

static std::string replaceContent(std::string content, const std::string& s1, const std::string& s2)
{
    if (s1.empty() || s1 == s2)
        return (content);

    std::string result;
    size_t pos = 0;
    size_t foundPos;

    while ((foundPos = content.find(s1, pos)) != std::string::npos)
    {
        result.append(content, pos, foundPos - pos);
        result.append(s2);
        pos = foundPos + s1.length();
    }
    result.append(content, pos, std::string::npos);
    return (result);
}

int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
        std::cout << YELLOW << "Usage: " << RESET << "./replace <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    const std::string folder = "files/";
    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];
    const std::string inputPath = folder + filename;

    std::ifstream inputFile(inputPath.c_str());
    if (!inputFile.is_open())
        return (print_error("Cannot open file: " + inputPath));

    std::string content;
    std::string line;
    while (std::getline(inputFile, line))
    {
        content += line;
        if (!inputFile.eof())
            content += "\n";
    }
    inputFile.close();

    std::string result = replaceContent(content, s1, s2);

    const std::string outputPath = inputPath + ".replace";
    std::ofstream outFile(outputPath.c_str());
    if (!outFile.is_open())
        return (print_error("Cannot create output file: " + outputPath));

    outFile << result;
    outFile.close();

    std::cout << BOLD << GREEN << "Success! " << RESET 
              << CYAN << filename << RESET << " processed into " 
              << CYAN << filename << ".replace" << RESET << std::endl;

    return (0);
}