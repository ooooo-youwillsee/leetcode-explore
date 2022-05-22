/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/19 06:48
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int rob(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    int n = nums.size();
    return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
  }

  int rob(vector<int> nums, int l, int r) {
    if (l > r) return 0;
    if (l == r) return nums[l];

    vector<int> dp(r - l + 2, 0);
    dp[1] = nums[l];

    for (int i = l + 1; i <= r; ++i) {
      dp[i + 1 - l] = max(dp[i - l], nums[i] + dp[i - 1 - l]);
    }

    return dp[r + 1 - l];
  }
};