
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
 

class Solution {
public:
	ListNode *temp = nullptr;
	ListNode *now = nullptr;
	ListNode *reverseList(ListNode* head) {
		while (head != nullptr)
		{

			temp = new ListNode(head->val);
			temp->next = now;
			now = temp;
			head = head->next;

		}


		return now;
	}
};


int main() {
	return 0;
}