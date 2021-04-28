#include<iostream>
using namespace std;





struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head)
			return head;
		auto findEnd = head;
		auto len = 1;
		while (findEnd->next)
		{
			len++;
			findEnd = findEnd->next;
		}
		findEnd->next = head;
		k = len - k % len;
		auto step = 0;
		while (step < k)
		{
			step++;
			findEnd = findEnd->next;
		}
		head = findEnd->next;
		findEnd->next = nullptr;
		return head;

	}
};

int main() {
	return 0;
}