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
//You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        /// base case
        if(head==NULL){
            return 0;
        }
        if(head->next ==nullptr){
            return nullptr;
        }
    int len = 0;
        // used for delete operation 
     ListNode *one=head,*two=head;
        while(one!=NULL){
            len++;
        one=one->next;
        }
        /// now find mid
    int mid = len/2;
        for(int i =0;i<mid-1;i++){
            two=two->next;
        }
        
            two->next=two->next->next;
        
        return head;

    }
};