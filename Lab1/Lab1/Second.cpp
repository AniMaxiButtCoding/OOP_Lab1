#include <iostream>
#include <string>
#include "Second.h"

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