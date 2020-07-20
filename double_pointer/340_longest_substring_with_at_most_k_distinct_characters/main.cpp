#include <vector>
#include <string>
#include <cassert>

using namespace std;


class Solution {
  public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
      int s_size = s.size();
      if(s_size == 0) return 0;
      if(k==0) return 0;
      int l=0,  r=0, max_len=0, cnt=0;
      vector<int> window_count(128, 0);
      char c;
      while(r<s_size) {
        c = s[r];
        if(window_count[c]++==0) ++cnt;
        while(cnt > k) {
          if(r-l > max_len) max_len = r-l;
          c = s[l];
          if(--window_count[c]==0) --cnt;
          ++l;
        }
        ++r;
      }
      if(cnt <= k) max_len = r - l > max_len ? r-l : max_len;
      return max_len;
    }
};

int main() {
  auto solution = Solution();
  int k = 2;
  string s("cbaaaaaaaa");
  int result = solution.lengthOfLongestSubstringKDistinct(s, k);
  assert(result==9);
  return 0;
}
