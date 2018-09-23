class Solution {
public:
  vector<int> findDuplicates(vector<int>& nums) {
    int l = nums.size();
    vector<int> ans;
    for (int i = 0; i < l; i++) {
      int n = abs(nums[i]);
      if (nums[n - 1] < 0) {
        ans.push_back(n);
      }
      nums[n - 1] = -nums[n - 1];
    }
    return ans;
  }
};
