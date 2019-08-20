#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	static vector<vector<string>> solveNQueens(int n) {            
		vector<vector<string>> res;
		int **ary = new int *[n];
		int *col_memory = new int[n];					//��col_memory�洢ʹ�ù�����
		for (int i = 0; i < n; ++i) {
			ary[i] = new int[n];
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				ary[i][j] = 0;
			}
		}
		for (int i = 0; i < n; ++i)
			col_memory[i] = 0;

		process(res, ary, col_memory, 0, n);			
		return res;

	}

private:
	static void process(vector<vector<string>> &res, int **ary, int *col_memory, int row, int n) {  //�ݹ��У�ѭ��������
		for (int col = 0; col < n; ++col) {
			bool flag = false;
			for (int i = row - 1, j = 1; i >= 0; --i, ++j) {
				if ((col - j >= 0 && ary[i][col - j] == 1) || (col + j < n && ary[i][col + j] == 1)) {   //���б������û��1
					flag = true;
					break;
				}
			}
			if (flag)
				continue;
			if (col_memory[col] == 1)     //������Ƿ���1
				continue;
			else {
				ary[row][col] = 1;
				col_memory[col] = 1;
				if (row == n - 1) {
					vector<string> one;
					for (int j = 0; j < n; ++j) {
						string str;
						for (int i = 0; i < n; ++i) {
							if (ary[j][i] == 0)
								str.push_back('.');
							else
								str.push_back('Q');
						}
						one.push_back(str);
					}
					res.push_back(one);
				}
				else {
					process(res, ary, col_memory, row + 1, n);
				}
			}
			ary[row][col] = 0;     //ĳ�еݹ���ɽ��л��ݸ�λ
			col_memory[col] = 0;
		}
	}
};




int main() {
	Solution::solveNQueens(5);
	return 0;
}