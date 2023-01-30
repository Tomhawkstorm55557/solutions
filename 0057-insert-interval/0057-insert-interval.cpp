class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //is question ma bhai teen case hongaa pahela jisma koi overlapping nhi hogi before merging toh us vala maa hum yeh check kar langa ki voh overlape kar rha haa ki nhi by comparing the start of input to end of new interval jo given haa 2nd case ma interval hoga toh min max laga kaa karlanga tesra case ma koi overlap nhi hoga toh sidha  
        
        int n = intervals.size(),i=0;
        //we are storing our merge interval in vector res
        vector<vector<int>>res;
        // case1  no overlapping case
          while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }    
        //case2 overlapping
        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1] =max(newInterval[1],intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        //jab voh range sa bada haa aur koi chance nhi haa overlap kaa toh sidha dal danga
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};