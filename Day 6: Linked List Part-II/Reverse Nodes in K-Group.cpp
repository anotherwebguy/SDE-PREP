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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) return head;
        int cnt=0;
        for(ListNode* curr=head;curr!=NULL;curr=curr->next) cnt++;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *prev=dummy,*curr=dummy,*nex=dummy;
        while(cnt>=k){
            curr=prev->next;
            nex=curr->next;
            for(int i=1;i<k;i++){
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=curr->next;
            }
            prev=curr;
            cnt-=k;
        }
        return dummy->next;
    }
};

//O(N)-time
//O(1)-space
