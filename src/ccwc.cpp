#include "ccwc.h"
#include <sstream>

int wordCount(const std::string& input) 
{
    int count = 0;
    bool inWord = false;

    for (char c : input)
    {
        if (std::isspace(c))
        {
            if (inWord)
            {
                inWord = false;
                count++;
            }
        }
        else
        {
            inWord = true;
        }
    }

    if (inWord)
    {
        count++;
    }

    return count;
}

int byteCount(const std::string& input)
{
    return input.length();
}


int lineCount(const std::string& fileContent) 
{
    std::istringstream iss(fileContent);
    int lineCount = 0;
    std::string line;

    while (std::getline(iss, line)) {
        lineCount++;
    }

    return lineCount;
}
