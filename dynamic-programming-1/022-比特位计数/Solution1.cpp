/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/31 07:18
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> ans(n + 1);
    vector<int> dp(n + 1);

    for (int i = 1; i <= n; ++i) {
      dp[i] = i % 2 == 0 ? dp[i / 2] : dp[i - 1] + 1;
      ans[i] = dp[i];
    }

    return ans;
  }
};