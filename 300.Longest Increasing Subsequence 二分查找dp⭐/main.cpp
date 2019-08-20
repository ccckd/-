#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    static int lengthOfLIS(vector<int>& nums) {
        if(!nums.size())
            return 0;
        int max = 1;
        int res = 1;
        vector<int> dp;
        dp.push_back(1);
        for(int i = 1; i < nums.size(); ++i){
            for(int j = 0; j < dp.size(); ++j){
                if(nums[i] > nums[j]){
                    if(dp[j] + 1 > max)
                        max = dp[j] + 1;
                }
            }
            dp.push_back(max);
            if(max > res)
                res = max;
            max = 1;
        }
        return res;
    }


    static int lengthOfLIS_bin(vector<int>& nums) {
        vector<int> tail(nums.size());
        int size = 0;
        for (int x : nums) {
            int i = 0, j = size;
            while (i != j) {             //二分搜索找到当前数对应tail中的位置，
                int m = (i + j) / 2;
                if (tail[m] < x)
                    i = m + 1;
                else
                    j = m;
            }
            tail[i] = x;
            if (i == size) ++size;
        }
        return size;
    }
};


int main() {
    vector<int> v  = {3, 5, 6, 2, 7};
    Solution s;
    int res = s.lengthOfLIS_bin(v);
    cout << res << endl;
    return 0;
}