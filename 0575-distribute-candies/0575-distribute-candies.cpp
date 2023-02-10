class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        set<int>s;
        for(auto i : candyType){
            s.insert(i);
        }
        int m = s.size();
        return min(n/2,m);
    }
};