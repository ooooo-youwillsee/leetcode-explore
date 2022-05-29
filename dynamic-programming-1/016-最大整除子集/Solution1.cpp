/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/26 07:12
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    if (nums.size() == 1) return nums;

    sort(nums.begin(), nums.end());

    int n = nums.size();
    int cnt = 0, k = 0;
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (nums[i] % nums[j] == 0) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      // 更新最大的长度和最大对应的索引
      if (dp[i] > cnt) {
        cnt = dp[i];
        k = i;
      }
    }

    // 通过最大值得位置来倒推，每一个值对应的个数相差必须为1
    vector<int> ans(cnt);
    ans[cnt - 1] = nums[k];
    for (int i = cnt - 2; i >= 0; --i) {
      for (int j = k - 1; j >= 0; j--) {
        if (ans[i + 1] % nums[j] == 0 && dp[j] == cnt - 1) {
          ans[i] = nums[j];
          k = j;
          cnt--;
          break;
        }
      }
    }

    return ans;
  }
};