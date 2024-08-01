#include <unordered_set>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_set<long long> st;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        st.insert(1);
        pq.push(1);
        
        int cnt = 0;
        while (cnt < n - 1) {
            long long top = pq.top();
            pq.pop();
            
            long long two = top * 2, three = top * 3, five = top * 5;
            if (two <= INT_MAX && st.find(two) == st.end()) {
                pq.push(two);
                st.insert(two);
            }
            if (three <= INT_MAX && st.find(three) == st.end()) {
                pq.push(three);
                st.insert(three);
            }
            if (five <= INT_MAX && st.find(five) == st.end()) {
                pq.push(five);
                st.insert(five);
            }
            cnt++;
        }
        
        return pq.top();
    }
};
