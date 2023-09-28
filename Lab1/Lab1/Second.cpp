#include <iostream>
#include <string>

struct mathin {
    double avg;
    double havg;
};

bool comp(const double& a, const double& b) {

    int sumA;
    int sumB;
    std::string numStr = std::to_string(a);
    size_t decimalPos = numStr.find('.');

    if (decimalPos != std::string::npos) {
        sumA = 0;
        for (size_t i = decimalPos + 1; i < numStr.length(); ++i) {
            sumA += numStr[i] - '0';
        }
    }

    numStr = std::to_string(b);
    decimalPos = numStr.find('.');

    if (decimalPos != std::string::npos) {
        sumB = 0;
        for (size_t i = decimalPos + 1; i < numStr.length(); ++i) {
            sumB += numStr[i] - '0';
        }
    }

    return sumA < sumB;
}

mathin means(double arr[], int a)
{
    mathin result;
    double temp[10]{};
    double n = 0;
    for (int i = 0; i < a; i++)
    {
        temp[i] = arr[i];
        if (temp[i] != 0)
        {
            n++;
        }
    }
    double sum = 0;
    result.avg = 0;
    for (int i = 0; i <= n; i++) 
    {
        sum += arr[i];
    }
    result.avg = sum / n;
    double harm_mean = 0;
    for (size_t e = 0; e < n; ++e)
    {
        if (arr[e] != 0)
        {
            harm_mean += 1.0 / arr[e];
        }
    }

    result.havg = n / harm_mean;
    return result;
}