#include<iostream>
#include<vector>
#include<string>
using namespace std;



class Solution {
public:
	string convert(string s, int numRows) {
		
		int t = numRows + numRows - 2;
		vector<string> res(numRows);
		for (auto i = 0; i < s.size(); i++) {
			int row = i % t;
			if (row > numRows - 1) row = t - row;
			res[row] += s[i];
			
		}

		string ans;

		for (string str : res) {
			ans += str;
		}

		cout << ans << endl;
		return ans;

	}
};

int main() {
	auto s = Solution();
	s.convert("A", 1);
	return 0;
}