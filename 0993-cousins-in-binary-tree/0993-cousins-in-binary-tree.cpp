class Solution {
public:
    
    int depth_x = 0;
    
    int depth_y = 0;
    
    int parent_x = -1;
    
    int parent_y = -1;
    
    void dfs(TreeNode* root, int x, int y, int depth, int parent)
    {
        if(root == NULL)
            return;
        
        // x is found
        
        if(root -> val == x)
        {
            depth_x = depth;
            
            parent_x = parent;
        }
        
        // y is found
        
        if(root -> val == y)
        {
            depth_y = depth;
            
            parent_y = parent;
        }
        
        // call for left child
        
        dfs(root -> left, x, y, depth + 1, root -> val);
        
        // call for right child
        
        dfs(root -> right, x, y, depth + 1, root -> val);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        // call dfs
        
        dfs(root, x, y, 0, -1);
        
        // check condition
        
        if(depth_x != depth_y)
            return false;
        
        if(depth_x == depth_y)
            return parent_x != parent_y;
        
        return false;
    }
};