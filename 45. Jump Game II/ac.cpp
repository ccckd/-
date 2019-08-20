#include<vector>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int dp[nums.size() + 10];
        dp[0] = 0;
        int start = 0;
        int step;
        for (int i = 0; i < nums.size() && start + 1 < nums.size(); ++i)
        {
            step = i + nums[i];
            for (int j = start + 1; j <= step; ++j){
                dp[j] = dp[i] + 1;
            }
            start = step > start ? step : start;
            
        }
        return dp[nums.size() - 1];
    }
};

int main(){
    Solution s;
    vector<int> vec = {2, 1};
    s.jump(vec);
}