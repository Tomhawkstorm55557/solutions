class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        long long sum =0;
        priority_queue<int>pq;
        for(int i =0;i<reward1.size();i++){
        pq.push(reward1[i]-reward2[i]);
            sum+=reward2[i];
            
            
        }
    
        while(k!=0){
       sum+=     pq.top();
         pq.pop();
            k--;
        }
        return sum;
    }
};