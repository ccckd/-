#include <cstdlib>
#include <iostream>

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int a = 0; a * a <= c;  a++)
        {
            double b = sqrt(c - a * a);
            if (b - floor(b) != 0)
                continue;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    std::cout << s.judgeSquareSum(999999999) << std::endl;
    return 0;
}