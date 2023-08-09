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
    ListNode* reverseList(ListNode* head) {
        if(head ==NULL){
            return NULL;
        }
         ListNode* p  =NULL;
        
          ListNode* nxt  = head;
           ListNode*  curr =  head;
        // abb  revere kardoo like we did in two pointers
        while(curr!=NULL){
            nxt = curr->next;
            curr->next = p;
            p = curr;
            curr= nxt;
        }
        return p;
    }
};