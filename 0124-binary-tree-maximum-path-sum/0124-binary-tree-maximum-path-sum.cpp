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
    int maxi = INT_MIN;
   int solve(TreeNode* curr){
       if(!curr){
           return 0;
           
       }
       int lsum = max(0,solve(curr->left));
       int rsum = max(0,solve(curr->right));
       maxi = max(maxi,lsum+rsum+curr->val);
       return curr->val+max(lsum,rsum);
           
   }
    int maxPathSum(TreeNode* root) {
        int psuedo = solve(root);
        return maxi;
    }
};