#include <string>

void avgsum(std::string data)
{
    int b = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i <= b; i++)
    {
        i = 4;
    }
}
class gfg {
public:
    int getSum(int n)
    {
        int sum = 0;
        while (n != 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        return sum;
    }
};
// unfinished code, will finish later.