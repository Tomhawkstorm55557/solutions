class Solution {
public:
    
    
    //A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).
    //You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:
    //Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.
    int maxConsecutiveAnswers(string ans, int k) {
        int n = ans.length();
        int len =0;
        //create a map 
        unordered_map<char,int>mp;
        for(int i =0;i<n;i++){
            mp[ans[i]]++;
            // find karo usaa jisaa replace karna ha
            int less = min(mp['T'],mp['F']);
            // cndtn --> check can we replace it 
            if(less<=k){
                len++;
            }
            else{
                // left part remove
                mp[ans[i-len]]--;
            }
        }
        return len;
    }
};