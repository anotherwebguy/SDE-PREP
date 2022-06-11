/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool nocycle(ListNode* head){
        ListNode *slow=head,*fast=head;
        while(slow && fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return false;
        }
        return true;
    }
    
    ListNode *detectCycle(ListNode *head) {
        if(nocycle(head)) return NULL;
        ListNode *slow=head,*fast=head;
        do{
            fast=fast->next->next;
            slow=slow->next;
        } while(slow!=fast);
        slow=head;
        while(slow!=fast){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};

//O(N)-time
//O(1)-space
