class Solution {
public:
    int numTrees(int n) {
        int ans =0;
        if(n<=1){
            return 1;
            
        }
        for(int i =1;i<=n;i++){
            ans+=numTrees(i-1)*numTrees(n-i);
}
        return ans;
    }
};