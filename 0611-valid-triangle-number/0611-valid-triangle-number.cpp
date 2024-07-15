class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cnt =0;
        // Iterate over each element as the first element of the triangle
        for (int i = 0; i < n - 2; i++) {
            int k = i + 2;  // Initialize k for the third element of the triangle
            for (int j = i + 1; j < n - 1 && nums[i] != 0; j++) {
                // Find the maximum k such that nums[i] + nums[j] > nums[k]
                while (k < n && nums[i] + nums[j] > nums[k]) {
                    k++;
                }
                // Add the number of valid triangles with nums[i] and nums[j] as two sides
                cnt += k - j - 1; // Corrected the count update
            }
        }
        
        return cnt;
    }
};