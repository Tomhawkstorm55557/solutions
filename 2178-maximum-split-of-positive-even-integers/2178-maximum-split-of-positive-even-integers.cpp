class Solution {
public:
    vector<long long> maximumEvenSplit(long long num) {
        if((num%2) !=0 )
        return {};

        vector<long long>ans;
        long long counter=2;

        while((num-counter)>=0)
        {
            ans.push_back(counter);
            num=num-counter;
            counter=counter+2;
        }
        if(num==0)  //num has utilized fully
        return ans;

        
         ans[ans.size()-1]=ans[ans.size()-1]+num;
         return ans;
    }
};