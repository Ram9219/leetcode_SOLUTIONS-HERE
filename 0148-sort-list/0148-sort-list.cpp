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
 //ise merge sort se kar lete hai 
class Solution {
public:
ListNode *getmid(ListNode*head){
    if(head==nullptr || head->next==nullptr)return head;
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* merge(ListNode*l1,ListNode*l2){
    if(!l1)return l2;
    if(!l2)return l1;
    if(l1->val<l2->val){
        l1->next=merge(l1->next,l2);
        return l1;
    }
    else{
        l2->next=merge(l1,l2->next);
        return l2;
    }

}
    ListNode* sortList(ListNode* head) {
        //pahla case --->empty ya 1 element ho to sorted hai 
        if(head==nullptr || head->next==nullptr)return head;
        //do parts me tod diya 
        ListNode* mid=getmid(head);//mid nikal liya bole to split kar diya 
        ListNode*right=mid->next;//yahi hai jo right ko alag kar rha hai 

        mid->next=nullptr;//that means ki aab left alag aur right alag ho chuka hai 
        ListNode *left=sortList(head);//apna poora kaam khatam karke aa pahle 
        right=sortList(right);//aur  tu bhi 
        return merge(left,right);

    }
};