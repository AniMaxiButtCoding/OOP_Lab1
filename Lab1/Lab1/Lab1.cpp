#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Second.h"

int main(int argc, char** argv)
{
    const std::string numbers = "0123456789.,";
    std::string filename;
    double data[10]{};
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
                data[b] = std::stod(varName);
                b += 1;
                continue;
            }
            data[b] = std::stod(line);
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
        for (int i = 1; i < argc; i++)
        {
            data[i] = atof(argv[i]);
        }
    }
    else
    {
        for (int i = 0; i <= b; i++)
        {
            if (std::to_string(data[i]).find_first_not_of(numbers) != std::string::npos)
            {
                std::cout << "Ошибка! Аргументы должны быть числами!";
            }

        }
    }
    int n = sizeof(data) / sizeof(data[0]);
    std::sort(data, data + n, comp);
    for (int i = 0; i < n; i++)
    {
        std::cout << data[i] << " ";
    }
}