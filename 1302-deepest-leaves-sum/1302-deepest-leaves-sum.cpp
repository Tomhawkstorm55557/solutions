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
    int sum ,  deeplvl;
    void solve( int curr, TreeNode*root){
        if(!root){
            return ;
        }
     
        if(deeplvl == curr ){
            sum+=root->val;
        }
        else if(curr>deeplvl){
            deeplvl = curr;
            sum = root->val;
        }
        solve(curr+1,root->left);
        solve(curr+1,root->right);
        
            
        
    }
    int deepestLeavesSum(TreeNode* root) {
       deeplvl =0;
       sum = 0;
       solve(0,root);
        return sum ;
        
    }
};