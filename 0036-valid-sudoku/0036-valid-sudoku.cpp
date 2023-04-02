class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& box) {
        set<string>s;
        for(int i =0;i<9;i++){
            for(int j =0;j<9;j++){
                if(box[i][j]!='.'){
                   string row = "row"+to_string(i)+box[i][j];
                   string col = "col"+to_string(j)+box[i][j];
                      string boxe = "box"+to_string((i/3)*3+(j/3))+box[i][j];
                  if(s.find(row)==s.end()&&s.find(col)==s.end()&&s.find(boxe)==s.end()){
                      s.insert(row);
                      s.insert(boxe);
                      s.insert(col);
                  }
                    else{
                        return false;
                    }
                 
                }
            }
        }
        return true;
        
    }
};