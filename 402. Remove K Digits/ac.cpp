#include<string>
using namespace std;


class Solution {
public:
    string removeKdigits(string num, int k) {
        while(k > 0){
            int i = 0;
            int j = 1;
            while(num[i] <= num[i + 1] && i + 1 < num.size())              
                i++;  
            if(num[i + 1] == '0' && i == 0){
                j = i + 1;
                while(num[j] == '0')
                    j++;
                num.erase(i, j - i);
            }else
                num.erase(i, 1);
            k--;   
        }
        return num == "" ? "0" : num;
    }
};

int main(){
    Solution s;
    string a = "112";
    s.removeKdigits(a, 2);
}