class Solution {
public:
    int timeRequiredToBuy(vector<int>& tic, int k) {
        //lets start queue 
        int time =0;
        queue<pair<int,int>>st;
        for(int i =0;i<tic.size();i++){
            st.push({tic[i],i});
        }
        while(!st.empty()){
            // cndtn 
        pair<int,int>tmp = st.front();
        st.pop();
        --tmp.first;
          ++time;  
        // now apply cdtn 
       if(tmp.first==0&&tmp.second == k){
           break;
       }
           else if(tmp.first != 0){
           st.push({tmp.first,tmp.second});
       }     
            
}
        return time;
    }
};