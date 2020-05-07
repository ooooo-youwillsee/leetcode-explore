package com.ooooo;

import java.util.HashSet;
import java.util.Set;

/**
 * @author leizhijie
 * @since 2020/5/7 21:55
 */
public class Solution1 {

  public int lengthOfLongestSubstring(String s) {
    int l = 0, r = -1, ans = 0;
    Set<Character> set = new HashSet<>();
    while (l < s.length()) {
      if (r + 1 < s.length() && !set.contains(s.charAt(r + 1))) {
        set.add(s.charAt(++r));
      } else {
        set.remove(s.charAt(l++));
      }
      ans = Math.max(ans, r - l + 1);
    }
    return ans;
  }

  private static void test(String s) {
    Solution1 solution1 = new Solution1();
    System.out.println(solution1.lengthOfLongestSubstring(s));
  }

  public static void main(String[] args) {
    test("abba");
    test("abcabcbb");
    test("bbbbb");
    test("pwwkew");
  }
}
