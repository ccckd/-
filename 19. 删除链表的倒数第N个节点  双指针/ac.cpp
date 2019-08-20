struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 




class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        auto temp = head;
        int count = 1;
        while (temp->next)
        {
            temp = temp->next;
            count++;
        }
        if(count == 1)
            return nullptr;

        temp = head;
        int res = count - n - 1;
        while(res > 0){
            temp = temp->next;
            res--;
        }
        if(res == -1){
            return head->next;
        }else{
            temp->next = temp->next->next;
            return head;
        }
    };
};