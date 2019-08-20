struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if(l1 == NULL){
                return l2;
            }else if(l2 == NULL){
                return l1;
            }

            ListNode *ln = nullptr;

            if(l1->val <= l2->val){
                ln = l1;
                ln->next = mergeTwoLists(l1->next, l2);
            }else{
                ln = l2;
                ln->next = mergeTwoLists(l1, l2->next);
            }

            return ln;

        }
    };

