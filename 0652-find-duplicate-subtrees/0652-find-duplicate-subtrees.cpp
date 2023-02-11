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
   
        vector<TreeNode*>ans;
        unordered_map<string,int>subtree;
      string solver(TreeNode* root){
          //edge case
          if(root ==NULL){
              return "";
          }
          string left = solver(root->left);
          string right = solver(root->right);
          // making a subtreee
       string s = "(" + left + to_string(root->val) + right + ")";   
          // storing the subtreee
             if(subtree[s]!=-1){
              subtree[s]++;
          }
          if(subtree[s]>1){
              ans.push_back(root);
                subtree[s]=-1;;
          }
          return s;
      }
     vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solver(root);
         return ans;
        
    }
};