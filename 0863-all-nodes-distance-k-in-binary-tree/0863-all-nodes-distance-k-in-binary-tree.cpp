/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
///Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// pura tree ma traverse karna haa
// approach -->  we  map a tree with its parent and child
/// use --> set to store visited 
// use bfs to find the target and traverse until we didnt react k ===0 
/// use a vector to store all the answers
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>mp;
  
    // this will give ous map 
    void mapTree(TreeNode*parent, TreeNode*child){
        /// base cndts
        if(child==NULL){
return ;
        }
    if(parent == NULL) parent = child;
        else{
            mp[child]=parent;
        }
        mapTree(child,child->right);
        mapTree(child,child->left);
    }
        
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
        /// step 1 --> call the map
        // make an queue
        int dis =0;
        queue<TreeNode*>qt;
          unordered_set<TreeNode*>st;
    vector<int>ans;
        mapTree(NULL,root);
        /// now we have map so we can start applying bfs
        qt.push(target);
        st.insert(target);
        while(!qt.empty()){
            int sz = qt.size();
            for(int i =0;i<sz;++i){
                auto currnode = qt.front();
                auto left = currnode->left;
                auto right = currnode->right;
                qt.pop();
                /// now marke them as visited and push them in quue
                if(left!=NULL&&st.count(left)==0){
                      qt.push(left);
                    st.insert(left);
               
                }
                 if(right!=NULL&&st.count(right)==0){
                          qt.push(right);
                    st.insert(right);

                }
                /// this is main part
                if(mp[currnode]&&st.count(mp[currnode])==0){
                      st.insert(mp[currnode]);
                    qt.push(mp[currnode]);
                 
                }
                if(k == dis){
                    ans.push_back(currnode->val);
                }
                 
            }
            dis++;
            if(dis>k){
                break;
            }
        }
        return ans;
    }
};