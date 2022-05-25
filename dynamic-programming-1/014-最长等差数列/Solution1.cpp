/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/23 06:49
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int longestArithSeqLength(vector<int> &nums) {
    int n = nums.size();

    int ans = 0;
    // dp[i][j]: 表示以第i个元素结尾的，差值为j的最大长度
    vector<vector<int>> dp(n, vector<int>(1001, 1));

    for (int i = 0; i < n; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        int x = nums[i] - nums[j] + 500;
        dp[i][x] = max(dp[i][x], dp[j][x] + 1);
        ans = max(ans, dp[i][x]);
      }
    }

    return ans;
  }
};