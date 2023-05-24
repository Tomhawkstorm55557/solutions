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
    ListNode* removeElements(ListNode* head, int val) {
        ///base case
        if(head==NULL){
            return NULL;
        }
        /// if all element same
        while(head!=NULL&&head->val==val){
            head=head->next;
        }
    ListNode* dummy = new ListNode;
        dummy -> next = head;
        ListNode* pointer = dummy;   
    
        //basic case
        while(pointer->next){
            if(pointer->next->val==val){
                pointer->next=pointer->next->next;
            }
            else{
                pointer=pointer->next;
            }
        }
        return dummy->next;
        
    }
};