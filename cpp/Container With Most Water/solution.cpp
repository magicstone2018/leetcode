class Solution {
public:
  int maxArea(vector<int>& height) {
    int result = 0;
    int size = height.size();
    int w1 = 0;
    int w2 = size - 1;
    while (w1 < w2) {
      int w = w2 - w1;
      int h = min(height[w1], height[w2]);
      int area = w * h;
      if (area > result) {
        result = area;
      }
      if (height[w1] <= height[w2]) {
        while (height[w1] <= h && w1 < w2) {
          w1++;
        }
      } else {
        while (height[w2] <= h && w1 < w2) {
          w2--;
        }
      }
    }
    return result;
  }
};
