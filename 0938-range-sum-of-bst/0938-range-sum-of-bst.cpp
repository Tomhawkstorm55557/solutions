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
void sum(TreeNode* root, int low, int high,vector<int>& arr)
{
    if (root==NULL)
        {
            return ;
        }
        if(root->val>=low && root->val<=high)
        {
            arr.push_back(root->val);
        }
        sum(root->left,low,high,arr);
        sum(root->right,low,high,arr);

}

    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        vector<int> arr;
       sum(root, low, high,arr);
       int add=0;
       for(int i =0;i<arr.size();i++)
       {
           add= add+arr[i];
       }
       return add;

    }
};