/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/31 06:59
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m; ++i) {
      dp[i + 1][0] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
      dp[0][i + 1] = i + 1;
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (word1[i] == word2[j]) {
          dp[i + 1][j + 1] = dp[i][j];
        } else {
          dp[i + 1][j + 1] = min(dp[i][j + 1] + 1, dp[i + 1][j] + 1);
        }
      }
    }

    return dp[m][n];
  }
};
