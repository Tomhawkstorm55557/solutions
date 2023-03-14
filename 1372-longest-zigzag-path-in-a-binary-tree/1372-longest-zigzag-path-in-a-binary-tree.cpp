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
    int ans = 0;
    void helper(TreeNode*root,int rht,int lft){
        if(root==NULL){
            return ;
        }
        if(root->right){
            ans = max(ans,lft+1);
            helper(root->right,lft+1,0);
        }
        if(root->left){
            ans=max(ans,rht+1);
            helper(root->left,0,rht+1);
        }
        
    }
    int longestZigZag(TreeNode* root) {
        helper(root,0,0);
        return ans;
    }
};