class Solution {
public:
    vector<vector<int>> result;
    
    void comSum(vector<int> &curr, int curInd, int sum, vector<int> &candidates, int target, int n){
        if(sum == target){
            result.push_back(curr);
            return;
        }      
        else if(sum > target){
            return;
        }
        
        for(int i = curInd; i < n; i++){
            curr.push_back(candidates[i]);
            sum += candidates[i];
            comSum(curr, i, sum, candidates, target, n);
            sum -= candidates[i];
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        int sum = 0;
        int n = candidates.size();
        comSum(curr, 0, sum, candidates, target, n);
        return result;
    }
};