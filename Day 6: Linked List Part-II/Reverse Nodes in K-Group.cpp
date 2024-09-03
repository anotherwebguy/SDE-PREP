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

class Solution {
public:
    ListNode* getkthNode(ListNode* temp, int k){
        k--;
        while(temp!=NULL && k>0){
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseLL(ListNode* temp){
        ListNode* prev = NULL;
        ListNode* curr = temp;
        while(curr!=NULL){
            ListNode* tp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevList = NULL;
        while(temp!=NULL){
            ListNode* kthNode = getkthNode(temp,k);
            if(kthNode==NULL){
                if(prevList){
                    prevList->next = temp;
                }
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(temp);
            if(temp==head){
                head = kthNode;
            } else {
                prevList->next = kthNode;
            }
            prevList = temp;
            temp = nextNode;
        }
        return head;
    }
};
