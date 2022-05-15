/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/12 06:35
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProduct(vector<int> &nums) {
    int n = nums.size();

    // dp[i][0]:  下标为 i 结尾的连续子数组的最小值
    // dp[i][1]:  下标为 i 结尾的连续子数组的最大值
    vector<vector<int>> dp(n, vector<int>(2, 1));
    dp[0][0] = dp[0][1] = nums[0];

    int ans = nums[0];
    for (int i = 1; i < n; ++i) {
      if (nums[i] > 0) {
        dp[i][0] = min(nums[i], nums[i] * dp[i - 1][0]);
        dp[i][1] = max(nums[i], nums[i] * dp[i - 1][1]);
      } else {
        dp[i][0] = min(nums[i], nums[i] * dp[i - 1][1]);
        dp[i][1] = max(nums[i], nums[i] * dp[i - 1][0]);
      }
      ans = max(ans, dp[i][1]);
    }

    return ans;
  }
};
