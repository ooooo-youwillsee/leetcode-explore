/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/18 07:04
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getMaxMatrix(vector<vector<int>> &matrix) {
    vector<int> ans(4);
    int maxAns = INT32_MIN;

    int m = matrix.size(), n = matrix[0].size();

    for (int i = 0; i < m; ++i) {
      vector<int> cols(n);
      for (int j = i; j < m; ++j) {
        for (int k = 0; k < n; ++k) {
          cols[k] += matrix[j][k];
        }

        //  计算一维数组的最大连续数组和
        vector<int> dp(n + 1, 0), dpL(n + 1, 0);
        for (int k = 0; k < n; ++k) {
          if (dp[k] > 0) {
            dp[k + 1] = cols[k] + dp[k];
            dpL[k + 1] = dpL[k];
          } else {
            dp[k + 1] = cols[k];
            dpL[k + 1] = k;
          }
          if (dp[k + 1] > maxAns) {
            ans[0] = i, ans[1] = dpL[k + 1], ans[2] = j, ans[3] = k;
            maxAns = dp[k + 1];
          }
        }
      }
    }

    return ans;
  }
};