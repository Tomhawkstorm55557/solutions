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
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>>res;
        queue<TreeNode*>q;
        if(root ==NULL){
            return res;
            
}
        q.push(root);
       
        while(!q.empty()){
            int size = q.size();
            vector<int>lvl;
            while(size--){
                TreeNode*curr = q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                lvl.push_back(curr->val);
            }
            res.push_back(lvl);
        }
        return res;
            
    }
};