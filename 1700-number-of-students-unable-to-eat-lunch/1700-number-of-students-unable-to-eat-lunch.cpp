class Solution {
public:
    int countStudents(vector<int>& stu, vector<int>& sand) {
        int i=0,cnt=0,j=0,n=stu.size();
        queue<int>dq;
        for(int it:stu)dq.push(it); 
        while(!dq.empty() && j<n*n){
            if(dq.front()==sand[i]){
                i++;
                dq.pop();
            }
            else{
                int t=dq.front();
                dq.pop();
                dq.push(t);
            }
            j++;
        }        
        
        if(dq.empty())return 0;
        else return dq.size();
    }
};