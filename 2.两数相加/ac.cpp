struct ListNode {
    int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *res = new ListNode(0);
		ListNode *temp = res;
		int ic = 0;
		while (l1 != nullptr || l2 != nullptr) {
			int a, b = 0;
			if (l1 == nullptr) {
				a = 0;
			}
			else {
				a = l1->val;
				l1 = l1->next;
			}
			if (l2 == nullptr) {
				b = 0;
			}
			else {
				b = l2->val;
				l2 = l2->next;
			}


			int sum = a + b + ic;
			if (sum > 9) {
				sum = sum % 10;
				ic = 1;
			}
			else {
				ic = 0;
			}
			temp->next = new ListNode(sum);
			temp = temp->next;
		}
		
		if (ic) {
			temp->next = new ListNode(ic);
		}

		return res->next;
		
		
		
	}
};

int main() {
	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	Solution s = Solution();
	s.addTwoNumbers(l1, l2);
	
}