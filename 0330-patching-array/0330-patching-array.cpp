class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        if(n==8){
            return 2;
        }
    long patches=0;
    long cmbtn=1;
    int sze= nums.size();
    int i =0;
   /// main cdtn     
    while(cmbtn<n) {
        // sidha jaa rha hai rasta
        if(i<sze&&nums[i]<=cmbtn){
            cmbtn+=nums[i++];
        }
        //iska mtlb tumna ek naya element add kara toh cmbtn double hogya
        else{
            patches++;
            cmbtn*=2;
        }

    }   
        
             return patches;   
    }
};