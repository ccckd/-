#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }

    std::vector<int> binarySearch(std::vector<int>& nums, int s, int e, int target)
    {
        if(e >= s) {
            int mid = (s + e) / 2;
            if (nums.at(mid) == target) {
                int l = mid, r = mid;
                while (1) {
                    if (l >= 0) {
                        if (nums.at(l) == target) {
                            l--;
                        } else {
                            l++;
                            break;
                        }

                    } else {
                        l++;
                        break;
                    }
                }

                while (1) {
                    if (r < nums.size()) {
                        if (nums.at(r) == target) {
                            r++;
                        } else {
                            r--;
                            break;
                        }

                    } else {
                        r--;
                        break;
                    }
                }
                return {l, r};
            } else if (nums.at(mid) < target) {
                return binarySearch(nums, mid + 1, e, target);
            } else {
                return binarySearch(nums, s, mid - 1, target);
            }
        }else{
            return {-1, -1};
        }
    }

};




int main()
{
    std::vector<int> t = {5, 7, 7, 8, 8, 10};
    Solution s;
    std::vector<int> res = s.searchRange(t, 6);
    return 0;
}
