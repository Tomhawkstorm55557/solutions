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
        
        
        // edge case
        if(!head){
            return NULL;
          }
        // defining two pointers
       ListNode  *newH,*tail;
        // pointig them toward head
        newH =tail = head;
        // now calculate the length of linked list
        int len =1;
       while(tail->next){
           len++;
         tail=tail->next;  
       } 
        //aab yeh last ma phoch gya toh last vala ko head sa jod data haa
        
        tail->next = head;
        // dealing the case agar k bada ho length saa
        k = k%len;
            for(auto i=0; i<len-k; i++) tail = tail->next; 
        newH = tail->next; 
        tail->next = NULL;
        
        return newH;
        
    }
};