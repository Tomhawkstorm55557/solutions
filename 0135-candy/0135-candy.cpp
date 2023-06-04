class Solution {
public:
    int candy(vector<int>& rating) {
  //Each child must have at least one candy.
//Children with a higher rating get more candies than their neighbors.      
        int n  = rating.size();
        if(rating.size()==1){
            return 1;
        }
        vector<int>cnt;
    //approach check left and rht

        for(int i = 0 ; i < n ; i++){
            cnt.push_back(1);
        }
     for(int i = 1 ; i < n ; i++){
            if(rating[i] > rating[i-1]){
                cnt[i] = cnt[i-1] + 1;
            }
        }
                for(int i = n-2 ; i >= 0 ; i--){
            if(rating[i] > rating[i+1] && cnt[i] <= cnt[i+1]){
                cnt[i] = cnt[i+1] + 1;
            }
        }

              return accumulate(cnt.begin() , cnt.end() , 0LL);
       
    }
};