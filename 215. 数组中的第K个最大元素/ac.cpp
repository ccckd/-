#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int end = nums.size() - 1;
		int begin = 0;
		int this_k = partition(nums, begin, end) + 1;
		while (this_k != k) {
			if (k < this_k) {
				end = this_k - 2;
				this_k = partition(nums, begin, this_k - 2) + 1;
			}else{
				begin = this_k;
				this_k = partition(nums, this_k, end) + 1;
			}
		}
		return nums[k - 1];

	}

	int partition(vector<int> &nums, int p, int q) {
		int r = nums[q];
		auto i = p - 1;
		auto j = p;
		while (j < q) {
			if (nums[j] > r) {
				swap(nums[j], nums[i + 1]);
				j += 1;
				i += 1;
			}
			else {
				j += 1;
			}
		}
		swap(nums[i + 1], nums[q]);
		return i + 1;
	}


	void swap(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

};


int main() {
	vector<int>a = { -1, -1 };
	Solution s = Solution();
	s.findKthLargest(a, 2);
}