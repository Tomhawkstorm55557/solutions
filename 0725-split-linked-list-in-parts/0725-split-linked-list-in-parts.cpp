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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        //pahela ength nikaloooo 
        int length=0;
        ListNode* temp=root;
        while(temp)
        {
            length++;
            temp=temp->next;
        }
        
        int numNodes=length/k; //the number of nodes that are to be in each group
        int extra=length%k;  //the extra nodes that are left
        int i=0;
        vector<ListNode*> res;
        temp=root;
        while(temp)
        {
            res.push_back(temp);
            // length ka hisab sa divide karta jaooo
            int currLen=1;
            while(currLen<numNodes)
            {
                temp=temp->next;
                currLen++;
            }
            if(extra>0 && length>k)
            {
                temp=temp->next;
                extra--;
            }
            ListNode* x=temp->next;
            temp->next=NULL;
            temp=x;
        }
       // jab divided part jada karnaa ho toh nullll addd kardnqaa
        while(length<k)
        {
            res.push_back(NULL);
            length++;
        }
        return res;
        
    }
};

        
    