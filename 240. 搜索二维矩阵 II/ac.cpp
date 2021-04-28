#include<iostream>
#include<vector>
using namespace std;




class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int max_col = matrix[0].size();
		int max_row = matrix.size();
		if (!max_col || !max_row)
			return false;
		auto i = 0;
		auto j = max_col - 1;
		while (j >= 0 && i < max_row) {
			if (target == matrix[i][j])
				return true;
			if (target < matrix[i][j]) {
				j -= 1;
			}
			else {
				i += 1;
			}
		}
		return false;
	}
};

int main() {

	Solution s = Solution();
	vector<int> a({ 1, 4, 7, 11, 15 });
	vector<int> b({ 2, 5, 8, 12, 19 });
	vector<int> c({ 3, 6, 9, 16, 22 });
	vector<int> d({ 10, 13, 14, 17, 24 });
	vector<int> e({ 18, 21, 23, 26, 30 });
	vector<vector<int>> vec({ a, b, c, d, e });
	auto res = s.searchMatrix(vec, 20);
	cout << res << endl;
}

