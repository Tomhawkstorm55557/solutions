class Solution {
public:
  vector<int> store;

int minJumps(vector<int> &nums, int start){
    if(start >= nums.size() - 1)
        return 0;
    if(store[start])
        return store[start];

    int minJump = 10000;
    for(int i = start + 1; i <= start + nums[start]; i++)
        minJump = min(minJump, 1 + minJumps(nums, i));
    store[start] = minJump;
    
    return store[start];
}

int jump(vector<int>& nums) {
    store = vector<int>(nums.size());
    return minJumps(nums, 0);
}
};