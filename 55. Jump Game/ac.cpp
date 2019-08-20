#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return true;
        for (int i = 0; i < n - 1; ++i){
            if(nums[i] == 0){
                int j = i - 1;
                for (; j >= 0; --j){
                    if(nums[j] + j > i)
                        break;
                }
                if(j == -1)
                    return false;
            }
        }
        return true;
    }
};


int main(){
    Solution s;
    vector<int> a = {2, 0, 0};
    bool res = s.canJump(a);
    return 0;
}