/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/11 19:44
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();
    int ans = nums[0];

    vector<int> dp(n);
    dp[0] = nums[0];

    for (int i = 1; i < n; ++i) {
      dp[i] = nums[i] + max(0, dp[i - 1]);
      ans = max(ans, dp[i]);
    }

    return ans;
  }
};
