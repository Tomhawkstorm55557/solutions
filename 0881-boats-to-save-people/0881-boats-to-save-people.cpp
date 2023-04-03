class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       sort(people.begin(),people.end()); 
    int cnt =0;    
    int start =0;
    int end = people.size()-1;
     while(start<=end){
         int sum = people[start] +people[end];
         if(sum<=limit){
             cnt++;
             start++;
             end--;
         }
         else{
             cnt++;
             end--;
         }
     }   
      return cnt;  
        
    }
};