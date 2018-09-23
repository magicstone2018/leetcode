class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = m == 0 ? 0 : matrix[0].size();
    for (int j = 0; j < n; j++) {
      if (!isToeplitzEqual(matrix, m, n, 0, j)) {
        return false;
      }
    }
    for (int i = 1; i < m; i++) {
      if (!isToeplitzEqual(matrix, m, n, i, 0)) {
        return false;
      }
    }
    return true;
  }
  
private:
  bool isToeplitzEqual(vector<vector<int>>& matrix, int m, int n, int a, int b) {
    for (int i = a + 1, j = b + 1; i < m && j < n; i++, j++) {
      if (matrix[i][j] != matrix[i - 1][j - 1]) {
        return false;
      }
    }
    return true;
  }
};
