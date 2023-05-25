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
    int length(ListNode* head){
        ListNode* temp=head;
        int i=0;
        while(temp!=NULL){
            i++;
            temp=temp->next;
        }
        return i;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
    if(head==NULL)
    return NULL;
    int len=length(head);
    if(k>len)
    return head;

    int count=0;
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* next=head->next;
    //reverse
    while(count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    //reverse ll
    if(next!=NULL)
        head->next=reverseKGroup(next,k);
    return prev;
    }
};