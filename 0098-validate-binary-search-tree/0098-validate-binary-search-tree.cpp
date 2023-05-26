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
    vector<int>nodes;
    void inorder(TreeNode* root){
          if (root->left) inorder(root->left);
        nodes.push_back(root->val);
        if (root->right) inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(int i =0;i<nodes.size()-1;i++){
           if (nodes[i] >= nodes[i+1]) return false;
}
       return true;   
    }
};