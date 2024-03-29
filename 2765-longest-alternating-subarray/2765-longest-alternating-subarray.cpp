class Solution {
public:
  int alternatingSubarray(vector<int>& nt) {
    int n = nt.size();
    int ans = -1;
    for (int i = 0; i < n; i++) {  // Iterate up to the last element as a starting point
      int len = 1;
      bool flag = true;
      for (int j = i + 1; j < n; j++) {  // Iterate from the next element after i
        if (nt[j] - nt[j - 1] != (flag ? 1 : -1)) {
          break;
        }
        flag = !flag;
        len++;
      }
      ans = max(len>1?len:-1, ans);
    }
    return ans;
  }
};
