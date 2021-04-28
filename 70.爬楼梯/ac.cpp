#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
	int climbStairs(int n) {
		vector<int> way = { 1, 2 };
		int i = 2;
		while (i < n)
		{
			way.push_back(way[i - 1] + way[i - 2]);
			i += 1;
		}
		return way[n - 1];
	}
};



int main() {
	Solution s = Solution();
	cout << s.climbStairs(4) << endl;
	
}