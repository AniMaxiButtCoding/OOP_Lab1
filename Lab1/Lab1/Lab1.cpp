#include <iostream>
#include <fstream>
#include <string>
#include "Second.cpp"

int main(int argc, char** argv)
{
    const std::string numbers = "0123456789.,";
    std::string filename;
    std::string data[10];
    int b = 0;
    if (argc < 2)
    {
        std::cout << "Аргументы не были введены, выберите файл с аргументами:";
        std::cin >> filename;
        std::ifstream myfile;
        myfile.open(filename);
        if (myfile.is_open())
        {
            std::ifstream infile(filename);
            std::string line, varName;
            std::string delimiter = " ";
            std::getline(infile, line);
            size_t pos = 0;
            while ((pos = line.find(delimiter)) != std::string::npos)
            {
                varName = line.substr(0, pos);
                line.erase(0, pos + delimiter.length());
                data[b] = varName;
                b += 1;
                continue;
            }
            data[b] = line;
        }
        else std::cout << "Unable to open file";

    }
    if (argc >= 2)
    {
        for (int i = 1; i < argc; i++)
        {
            if (std::string(argv[i]).find_first_not_of(numbers) != std::string::npos)
            {
                std::cout << "Ошибка! Аргументы должны быть числами!";
            }

        }
    }
    else
    {
        for (int i = 0; i <= b; i++)
        {
            if (data[i].find_first_not_of(numbers) != std::string::npos)
            {
                std::cout << "Ошибка! Аргументы должны быть числами!";
            }

        }
    }
}