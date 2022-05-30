/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/27 07:23
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s) {
    int n = s.size();

    int ans = 0;
    stack<int> s_;
    s_.push(-1);

    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        s_.push(i);
      } else {
        s_.pop();
        if (s_.empty()) {
          s_.push(i);
        } else {
          ans = max(ans, i - s_.top());
        }
      }
    }

    return ans;
  }
};

