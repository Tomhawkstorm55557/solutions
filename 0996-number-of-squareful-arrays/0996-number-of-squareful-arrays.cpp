class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0;
        pmt(A, 0, ans);
        return ans;
    }
    void pmt(vector<int> A, int idx, int& ans) {
        if (idx >= A.size()) {
            ++ans;
        }
        for (int i = idx; i < A.size(); ++i) {
            if (i > idx && A[i] == A[idx]) continue;
            swap(A[i], A[idx]);
            if ((idx == 0) || (idx > 0 && isSquare(A[idx] + A[idx - 1]))) {
                pmt(A, idx + 1, ans);
            }
        }
    }
    bool isSquare(int v) {
        int r = sqrt(v);
        return r * r == v;
    }
};