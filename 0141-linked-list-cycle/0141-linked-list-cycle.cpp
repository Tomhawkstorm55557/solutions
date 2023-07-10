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
    
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;;
        }
        ListNode *slow =head,*fast=head;
        while(fast && fast->next){
            // 2 ---> jump
            fast = fast->next->next;
            slow = slow->next;
        /// cndtn 
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};