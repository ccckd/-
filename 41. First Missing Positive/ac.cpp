#include<vector>
using namespace std;



class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(!nums.size())
            return 1;
        int i = 0;
        while(i < nums.size()){
            if(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]){        
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;   
            }else{
                i++;
            }
            
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};


int main(){
    Solution s;
    vector<int> vec = {1, 1};
    s.firstMissingPositive(vec);
}