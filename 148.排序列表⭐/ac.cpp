struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};



class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == nullptr) {
			return head;
		}
		else {
			return mergeSort(head);
		}
	}

	ListNode *mergeSort(ListNode *head) {
		if (head->next == nullptr) {
			return head;
		}

		ListNode *pre = head, *fast = head, *slow = head;

		while (fast != nullptr && fast->next != nullptr) {
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
			
		}

		pre->next = nullptr;
		return merge(mergeSort(head), mergeSort(slow));

		


	}

	ListNode *merge(ListNode *l, ListNode *r) {
		ListNode *contact = new ListNode(0);
		ListNode *temp = contact;
		while (l != nullptr && r != nullptr) {

			if (l->val <= r->val) {
				temp->next = l;
				l = l->next;
				temp = temp->next;
			}
			else {
				temp->next = r;
				r = r->next;
				temp = temp->next;
			}


		}

		if (l == nullptr) {
			temp->next = r;
		}
		if (r == nullptr) {
			temp->next = l;
		}

		return contact->next;
		
	}


};


int main() {

	int list[] = { 4, 1, 2, 3 };
	ListNode *L = new ListNode(0);
	ListNode *temp = L;
	for (int i = 0; i < 4; i++){
		ListNode *l = new ListNode(list[i]);
		temp->next = l;
		temp = temp->next;
	}

	Solution *S = new Solution();
	S->sortList(L->next);
	
}