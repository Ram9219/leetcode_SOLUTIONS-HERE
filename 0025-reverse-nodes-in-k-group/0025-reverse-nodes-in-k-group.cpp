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
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* groupPrev = dummy;

        while (true) {
            // Check karo ki remaining nodes >= k hain ya nahi
            ListNode* kth = getKthNode(groupPrev, k);
            if (!kth) break;

            ListNode* groupNext = kth->next;

            // Group ko reverse karne ki process
            ListNode* prev = kth->next;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            // Pointers ko update aur reconnect karo
            ListNode* tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }

private:
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};