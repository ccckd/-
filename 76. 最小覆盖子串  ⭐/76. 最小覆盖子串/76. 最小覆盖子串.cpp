#include "pch.h"
#include <iostream>
#include <string>
#include <assert.h>
#include <vector>

using namespace std;


//class Solution {
//public:
//	int list[58] = { 0 };
//
//	string minWindow(string s, string t) {
//		if (s.size() == 0)
//			return "";
//		int min = 999;
//		int res_l = 0;
//		int res_r = 0;
//		int l = 0;
//		int r = 0;
//
//		for (int i = l; i <= r; i++) {
//			list[s[i] - 'A']++;
//		}
//		while (r < s.size())
//		{
//			int len = r - l + 1;
//			if (len < t.size()) {
//				list[s[++r] - 'A']++;
//				continue;
//			}
//			else if(len == t.size())
//			{
//				if (isOk(t)) {
//					res_l = l;
//					res_r = r;
//					break;
//				}
//				else {
//					list[s[++r] - 'A']++;
//					continue;
//				}
//			}
//			else {
//
//				if (isOk(t)) {
//					if (len < min) {
//						min = len;
//						res_l = l;
//						res_r = r;
//					}
//					list[s[l++] - 'A']--;
//					continue;
//				}
//				else {
//					list[s[++r] - 'A']++;
//					continue;
//				}
//
//			}
//		}
//
//		return s.substr(res_l, res_r - res_l + 1);
//	}
//
//private:
//
//	bool isOk(string t) {
//		for (auto c : t) {
//			if (!list[c - 'A'])
//				return false;
//		}
//		return true;
//	}
//};


//用两个指针来找最小的覆盖子串
//用一个vector储存每个字母的 次数？

//map应该理解为当前的滑窗对于某字母还差几个，因此先把t所含的字母设为1，表示还差1个， 其他为0表示不欠
//仅仅在count为0即表示所有的t中的字符都已经不欠了，才移动begin试图缩短串的长度
//一旦移除一个需要的字符就把它变成：欠1个 count++后又继续移动end找这个欠的字符

class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> map(128, 0);
		for (auto c : t) map[c]++;
		int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
		while (end < s.size()) {
			if (map[s[end++]]-- > 0)                          
				counter--; //in t				
			while (counter == 0) { //valid					
				if (end - begin < d)  
					d = end - (head = begin);
				if (map[s[begin++]]++ == 0)					
					counter++;  //make it invalid
			}
		}
		return d == INT_MAX ? "" : s.substr(head, d);
	}
};


int main()
{
	Solution s;
	s.minWindow("ADOBECODEBANC", "ABC");

}

