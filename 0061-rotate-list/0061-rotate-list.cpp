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
        int n=1;
        //step 1 is calculate the size of ll
        ListNode* temp=head;
        if(head==NULL || k==0 )return head;
        while(temp->next){
            temp=temp->next;
            n++;
        }
        //step 2 make it circular 
        temp->next=head;
        //step 3 reduce the size of k 
        k=k%n;
        int steps=n-k;
        //step 4 find new tails 
        ListNode*newtail=head;
        for(int i=1;i<steps;i++){
            newtail=newtail->next;
        }
        //break 
        ListNode*newhead=newtail->next;
        newtail->next=NULL;
        return newhead;

    }
};