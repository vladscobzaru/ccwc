#include <iostream>
#include <fstream>
#include "ccwc.h"

int main(int argc, char* argv[])
{
    if (argc < 2 || argc > 4) 
    {
        std::cerr << "Usage: " << argv[0] << " [-c] [-l] [-w] <input_file>" << std::endl;
        return 1;
    }

    bool countBytes = true;
    bool countWords = true;
    bool countLines = true;
    

    if (argc > 1)
    {
        for (int i = 1; i < argc - 1; ++i)
        {
            std::string option(argv[i]);
            if (option == "-c")
            {
                countBytes = true;
            }
            else if (option == "-l")
            {
                countLines = true;
            }
            else if (option == "-w")
            {
                countWords = true;
            }
            else
            {
                std::cerr << "Unknown option: " << option << std::endl;
                return 1;
            }
        }
    }

    std::ifstream inputFile(argv[argc - 1]);

    if (!inputFile) 
    {
        std::cerr << "Error opening file: " << argv[argc - 1] << std::endl;
        return 1;
    }

    std::string fileContent((std::istreambuf_iterator<char>(inputFile)),
        std::istreambuf_iterator<char>());

    inputFile.close();

    if (countBytes)
    {
        int byteCountResult = byteCount(fileContent);
        std::cout << byteCountResult << " ";
    }

    if (countWords)
    {
        int wordCountResult = wordCount(fileContent);
        std::cout << wordCountResult << " ";
    }

    if (countLines) 
    {
        int lineCountResult = lineCount(fileContent);
        std::cout << lineCountResult << " ";
    }

    std::cout << argv[argc - 1] << std::endl;

    return 0;
}
