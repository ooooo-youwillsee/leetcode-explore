/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/27 07:41
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;

    // dp[i]: 表示以i结尾的子数组的个数
    vector<int> dp(n);

    for (int i = 2; i < n; ++i) {
      if (nums[i - 2] + nums[i] == 2 * nums[i - 1]) {
        dp[i] = 1 + dp[i - 1];
      }
      ans += dp[i];
    }

    return ans;
  }
};
