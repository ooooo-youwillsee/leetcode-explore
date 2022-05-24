/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/20 07:54
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int lenLongestFibSubseq(vector<int> &arr) {
    int n = arr.size();
    int ans = 0;

    // dp[i][j]： 表示以1,j 为结尾的最长序列
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // 因为这些数字都不相等，所以可以一次性加入，也可以在遍历过程中加入
    unordered_map<int, int> m_;

    for (int i = 2; i < n; ++i) {
      m_[arr[i - 2]] = i - 2;
      for (int j = i - 1; j >= 1; --j) {
        int sub = arr[i] - arr[j];
        if (m_.count(sub) && m_[sub] < j) {
          dp[i][j] = max(dp[i][j], dp[j][m_[sub]] == 0 ? 3 : dp[j][m_[sub]] + 1);
        }
        ans = max(ans, dp[i][j]);
      }
    }

    return ans >= 3 ? ans : 0;
  }
};
