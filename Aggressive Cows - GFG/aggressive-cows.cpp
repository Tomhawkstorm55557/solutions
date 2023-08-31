//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:


bool isPossible(const vector<int>& stalls, int cows, int distance) {
    int placedCows = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - lastPosition >= distance) {
            placedCows++;
            lastPosition = stalls[i];
        }

        if (placedCows >= cows) {
            return true;
        }
    }

    return false;
}

int maxMinDistance(const vector<int>& stalls, int cows) {
    int left = 1; // Minimum possible distance
    int right = stalls.back() - stalls.front(); // Maximum possible distance

    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(stalls, cows, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

    int solve(int n, int k, vector<int> &stalls) {
     sort(stalls.begin(), stalls.end());

    int result = maxMinDistance(stalls, k);
    return result;
        // Write your code here
    }
};    
    


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends