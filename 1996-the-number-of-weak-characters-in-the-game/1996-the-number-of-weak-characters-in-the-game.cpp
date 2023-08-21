class Solution {
public:
    /*You are playing a game that contains multiple characters, and each of the characters has two main properties: attack and defense. You are given a 2D integer array properties where properties[i] = [attacki, defensei] represents the properties of the ith character in the game.

A character is said to be weak if any other character has both attack and defense levels strictly greater than this character's attack and defense levels. More formally, a character i is said to be weak if there exists another character j where attackj > attacki and defensej > defensei.

Return the number of weak characters.*/
    bool static cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
              return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& pro) {
        int ans=0 ;
       sort(pro.begin(),pro.end(),cmp);
        int last = INT_MIN;
        int n = pro.size();
        for(int i =n-1;i>=0;i--){
             if(pro[i][1]<last)
            {
                ans++;
            }
            if(pro[i][1]>last)
            {
             last = pro[i][1];  
            }
        }
        return ans;
    }
};