class Solution {
public:
    int largestPerimeter(std::vector<int>& nums) {
        int n = nums.size();
        // Sort the array in non-decreasing order
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        
        // Iterate through the array to find the largest perimeter
        for (int i = 0; i < n - 2; ++i) {
            // Check if the three numbers can form a triangle
            if (nums[i] < nums[i + 1] + nums[i + 2]) {
                // Return the perimeter of the triangle
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        
        // Return 0 if no valid triangle is found
        return 0;
    }
};