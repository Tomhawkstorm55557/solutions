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

        int dia = 0;
        int md(TreeNode *temp){
            if(temp==NULL){
                return 0;
            }
            int l = md(temp->left);
            int r = md(temp->right);
            dia = max(dia,l+r);
            
            return (1+max(l,r)); 
        }
       
           int diameterOfBinaryTree(TreeNode* root) {
               md(root);
               return dia;
    }
};