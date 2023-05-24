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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ele=head;
        while(ele!=NULL&&ele->next!=NULL){
            if(ele->val==ele->next->val){
                      ListNode* temp=ele->next;
                      ele->next=ele->next->next;
                      delete(temp);
            }
            else{
                ele=ele->next;
            }
        }
        return head;
        
    }
};