class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        // making a 2d matrix question
        int i =0;
        int j = m[0].size()-1;
        //base cndthn
        while(i<m.size()&&j>=0){
            //case one when we got target
            if(m[i][j]==t){
                return true;
            }
            //jab target bada haa toh 
            else if(m[i][j]<t){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
}; 