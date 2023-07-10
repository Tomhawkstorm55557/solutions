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
    //Remove every node which has a node with a strictly greater value anywhere to the right side of it.

//Return the head of the modified linked list.

 
    ListNode* removeNodes(ListNode* head) {
       ListNode*p1 = head;
        stack<int>st;
        while(p1){
            // base cndtn
            if(st.empty()){
                st.push(p1->val);
            }
            //cndtn --> strictly greater value anywhere to the right side
            else{
             if(!st.empty()&&st.top()<p1->val){
                 while(!st.empty()&&st.top()<p1->val){
                 st.pop();
                 }
             }
                            st.push(p1->val);
            }

            p1=p1->next;
        }
        /// make a ll from stack
        ListNode*root =NULL;
        while(!st.empty()){
            ListNode*tmp = new ListNode;
            tmp ->val = st.top();
            tmp ->next = root;
            root=tmp;
            st.pop();
            
        }
        return root;
    }
};