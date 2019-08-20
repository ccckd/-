#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string s, res;
        for (int i = 1; i <= n; ++i){
            s.push_back(i + '0');
        }
        while(n > 1){
            int help = helper(n - 1);
            int seg = k == 0 ? n : k / help;
            k = k % help;
            if(k == 0){
                res.push_back(s[seg - 1]);
                s.erase(seg - 1, 1);
            }else {
                res.push_back(s[seg]);
                s.erase(seg, 1);
            }
            n--;
        }
        res.push_back(s[0]);
        return res;
    }

    int helper(int n){
        int res = 1;
        while(n > 0){
            res *= n;
            n--;
        }
        return res;
    }
};

int main(){
    Solution s;
    s.getPermutation(3, 2);
}
