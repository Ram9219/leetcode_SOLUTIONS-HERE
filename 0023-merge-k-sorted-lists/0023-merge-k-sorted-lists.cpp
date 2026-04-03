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
struct compare{
  bool operator()(ListNode*a,ListNode*b){
    return a->val>b->val;
  }  
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //min heap banate hai pah;e 
       priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(auto node:lists){
            if(node!=NULL){
                pq.push(node);
            }
        }
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while(!pq.empty()){
            ListNode* min=pq.top();
            pq.pop();
            tail->next=min;
            tail=tail->next;
            if(min->next!=NULL){
                pq.push(min->next);
            }
        }
        return dummy->next;
    }
};