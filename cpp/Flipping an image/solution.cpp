class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    const int m = A.size();
    const int n = m == 0 ? 0 : A[0].size();
    for (vector<int>& v : A) {
      for (int j = 0; j < n / 2; j++) {
        int i = n - 1 - j;
        if (v[j] == v[i]) {
          v[j] = 1 - v[j];
          v[i] = 1 - v[i];
        }
      }
      if (n % 2 == 1) {
        v[n / 2] = 1 - v[n / 2];
      }
    }
    return A;
  }
};
