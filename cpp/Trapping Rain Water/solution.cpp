class Solution {
private:
  int helper(vector<int>::iterator left, vector<int>::iterator right) {
    if (left + 1 >= right) {
      return 0;
    }
    vector<int>::iterator max_it = max_element(left + 1, right);
    if ((*max_it) < (*left) && (*max_it) < (*right)) {
      return calculate(left, right);
    }
    return helper(left, max_it) + helper(max_it, right);
  }
  int calculate(vector<int>::iterator left, vector<int>::iterator right) {
    int high = min(*left, *right);
    vector<int>::iterator it = left;
    int area = 0;
    while (++it < right) {
      area += (high - *it);
    }
    return area;
  }
  
public:
  int trap(vector<int>& height) {
    if (height.empty()) {
      return 0;
    }
    return helper(height.begin(), height.end() - 1);
  }
};
