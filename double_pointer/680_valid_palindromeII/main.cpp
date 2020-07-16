#include <string>
#include <cassert>

using namespace std;

class Solution {
  public:
    bool validPalindrome(string s) {
      return isValidPalindrome(s, 0, s.size()-1, false);
    }

    bool isValidPalindrome(string& s, int l, int r, bool updated) {
        while(l<=r) {
          if(s[l]==s[r]) ++l&&--r;
          else {
            if(updated) return false;
            return isValidPalindrome(s, l+1, r, true) or isValidPalindrome(s, l, r-1, true);
          }
        }
        return true;
    }
};


int main() {
  string s1 = string("abzczuuzcba");
  string s2 = string("abzcczcba");
  auto solution = Solution();
  assert(solution.validPalindrome(s1));
  assert(solution.validPalindrome(s2));
  return 0;
}
