class Solution {
     void backtrack(string tiles,int&count ,int levels){
        count ++;
        for(int i = levels;i<tiles.length();i++){
            if(i!=levels&&tiles[i]==tiles[levels]){
                continue;
            }
            swap(tiles[i],tiles[levels]);
            backtrack(tiles,count,levels+1);
            
        }
    }
public:
  
    int numTilePossibilities(string tiles) {
        int count = -1;
        sort(tiles.begin(),tiles.end());
        backtrack(tiles,count,0);
        return count;
        
    }
};