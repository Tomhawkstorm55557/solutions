/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
         queue<TreeNode*> q;
       if(root == NULL){
            return ans;
        }
           q.push(root);
       
        int f = 0;
        while(q.size()){
             vector<int>temp;
            int si = q.size();
            while(si--){
                TreeNode* tem = q.front();
                q.pop();
              if(tem->left!=NULL){
                  q.push(tem->left);
                  
              }  
                 if(tem->right!=NULL){
                  q.push(tem->right);
                  
              } 
                temp.push_back(tem->val);
                
            }
            if(f==0){
                f=1;
                ans.push_back(temp);
            }
            else{
                f=0;
                  reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
        }
        
        return ans;
        
    }
};