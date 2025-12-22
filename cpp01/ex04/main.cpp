#include "replace.hpp"

static int print_error(std::string message)
{
    std::cerr << RED << "Error: " << RESET << message << std::endl;
    return 1;
}

static std::string replaceContent(std::string content, const std::string& s1, const std::string& s2)
{
    if (s1.empty()) 
        return content;
    
    std::string result;
    size_t pos = 0;
    size_t foundPos;

    while ((foundPos = content.find(s1, pos)) != std::string::npos)
    {
        result += content.substr(pos, foundPos - pos);
        result += s2;
        pos = foundPos + s1.length();
    }
    result += content.substr(pos);
    return result;
}

int main(int argc, char const *argv[])
{
    if (argc != 4)
        return print_error("Usage: ./replace <filename> <s1> <s2>");

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
        return print_error("Could not open input file: " + filename);

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

    // 3. Çıkış dosyasını oluştur ve yaz
    std::ofstream outFile((filename + ".replace").c_str());
    if (!outFile.is_open())
        return print_error("Could not create output file.");

    outFile << result;
    outFile.close();

    return 0;
}