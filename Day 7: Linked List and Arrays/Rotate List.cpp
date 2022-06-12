/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int cnt=0;
        if(head==NULL) return head;
        for(ListNode* curr=head;curr!=NULL;curr=curr->next) cnt++;
        int x=k%cnt;
        if(x==0) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next=head;
        ListNode *slow=dummy, *fast=dummy;
        for(int i=1;i<=x;i++) fast=fast->next;
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* temp=slow->next;
        slow->next=NULL;
        fast->next=head;
        return temp;
    }
};

// O(N)-time
// O(1)-space
