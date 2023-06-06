class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        /// map haa aur stack haa
      /// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
        // Output: [-1,3,-1]
        // - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
        /// kya karna haa 
        // For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
        // yeh cndtn dekni haa        
        unordered_map<int,int>rec;
        stack<int>st;
        int n = nums2.size();
        for(int i =n-1;i>=0;--i){
            int ele = nums2[i];
           while(!st.empty()&&st.top()<=ele){
               st.pop();
           }
            int res = (st.empty()) ?-1:st.top();
            rec.insert({ele,res});
            st.push(ele);
        }
        vector<int>ans;
        for(auto x: nums1){
            ans.push_back(rec[x]);
        }
        return ans;
        
    }
};