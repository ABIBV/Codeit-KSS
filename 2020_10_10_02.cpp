/*
  Given a string ​ s, find the length of the longest substring without repeating characters.
  Example 1:
  Input: s = "abcabcbb"
  Output: 3
  Explanation: The answer is "abc", with the length of 3.
  Example 2:
  Input: s = "bbbbb"
  Output: 1
  Explanation: The answer is "b", with the length of 1.
  Example 3:
  Input: s = "pwwkew"
  Output: 3
  Explanation: The answer is "wke", with the length of 3.
  Notice that the answer must be a substring, "pwke" is a subsequence and not a
  substring.
  Example 4:Input: s = ""
  Output: 0
  Constraints:
  ● 0 <= s.length <= 5 * 10​ 4
  ● s​ consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include <set>

using namespace std;

int longestSubString(string s){
  int start = 0, end = 0, longLength = 1;
  set<char> visited;
  while(end < s.length()){
    if(visited.find(s[end]) != visited.end()) {
      visited.erase(s[start]);
      start++;
    } else {
      visited.insert(s[end]);
      end++;
    }

    if(visited.size() > longLength) {
      longLength = visited.size();
    }
  }
  return longLength;
}

int main() {
  string s = "abcabcbb";
  int longLength = longestSubString(s);
  cout<<longLength;
}