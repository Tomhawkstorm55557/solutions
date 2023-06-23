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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root == nullptr) {
            return 0;
        }
        
        priority_queue<long long, vector<long long>, greater<long long>> helper;
        queue<TreeNode*> pq;
        pq.push(root);

        while (!pq.empty()) {
            int size = pq.size();
            long long sum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = pq.front();
                pq.pop();

                if (curr->left) {
                    pq.push(curr->left);
                }
                if (curr->right) {
                    pq.push(curr->right);
                }

                sum += curr->val;
            }

            helper.push(sum);
            if (helper.size() > k) {
                helper.pop();
            }
        }
if(helper.size()<k) return -1;
        return helper.top();
    }
};

