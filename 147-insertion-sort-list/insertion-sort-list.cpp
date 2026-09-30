class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        
        while (head) {
            ListNode* curr = head;
            head = head->next;

            ListNode* temp = &dummy;

            while (temp->next && temp->next->val < curr->val) {
                temp = temp->next;
            }

            curr->next = temp->next;
            temp->next = curr;
        }

        return dummy.next;
    }
};