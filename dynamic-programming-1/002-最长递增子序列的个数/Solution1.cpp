/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/07 07:56
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findNumberOfLIS(vector<int> &nums) {
    int n = nums.size();

    // dp[i]: 以下标i结尾的，最长子序列的长度
    vector<int> dp(n, 1);
    // cnt[i]: 以下标i结尾，最长子序列的个数
    vector<int> cnt(n, 1);

    int maxL = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (nums[j] < nums[i]) {
          if (dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            cnt[i] = cnt[j];
          } else if (dp[j] + 1 == dp[i]) {
            cnt[i] += cnt[j];
          }
          maxL = max(maxL, dp[i]);
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (dp[i] == maxL) {
        ans += cnt[i];
      }
    }

    return ans;
  }
};
