class Solution {
public:
  int minMutation(string start, string end, vector<string>& bank) {
        
        //DATA STRUCTURE USED:- SET AND BFS
        
        //1.BASICALLY WHAT WE WILL BE DOING IS WE WILL FIRST PUSH IN SET ALL ELEMENTS IN BANK
        //2.WE WILL RETURN -1 IF END ELEMENT IS NOT PRESENT IN SET
        //3.THE SIMPLE APPROACH IS USING BFS, WHAT WE WILL BE DOING IS FIRST WE WILL PUSH START ELEMENT AND THEN WE WILL REPLACE EVERY ELEMENT WITH THE CHARACTERS A C G AND T AND CHECKS IF THAT STRING IS PRESENT IN THE SET OOR NOT
        //4.IF PRESENT WE WILL PUSH THE STRING IN QUEUE
        //5.FOR MEASURING THE STEPS WE WILL TAKE A STEP COUNTER WHICH WILL KEEP THE STEP COUNT FOR IT.
        //6.TIME COMPLEXITY WILL BE O(N)
        
        unordered_set<string>st{bank.begin(),bank.end()};
        //IF END IS NOT PRESENT IN SET THEN RETURN -1
        if(!st.count(end))
            return -1;
        queue<string>q;
        q.push(start);
        int steps=0,s;
        string cur,t;
        while(!q.empty())
        {
            s=q.size();
            while(s--)
            {
                cur=q.front();
            q.pop();
            //  IF WE REACH END OF MUTATION THEN SIMPLI RETURN STEP
            if(cur==end)
                return steps;
            //WE WILL REMOVE THE CUR AS TO AVOID ANY REPEATATION
            st.erase(cur);
            //NOW HERE WE WILL BE CHANGING THE CHARACTER IN CURR WITH A,C,G,T AND WILL BE CHECKING IF THAT STING IS IN SET OR NOT,IF YES THEN PUSH IT
            for(int i=0;i<8;i++)
            {
                string t=cur;
                t[i]='A';
                if(st.count(t)!=0)
                    q.push(t);
                t[i]='C';
                if(st.count(t)!=0)
                    q.push(t);
                t[i]='G';
                if(st.count(t)!=0)
                    q.push(t);
                t[i]='T';
                if(st.count(t)!=0)
                    q.push(t);
            }
            
            }
            steps++;
        }
        return -1;
    }
};