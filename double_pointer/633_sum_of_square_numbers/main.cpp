#include <math.h>
#include <cassert>

class Solution {
  public:
    bool judgeSquareSum(int c) {
      if (c < 0) return false;
      int up=sqrt(c);
      int small=0, big=up;
      int tmp;
      while(small<=big) {
        tmp = small*small - c + big*big;  // avoid overflow
        if(tmp>0) --big;
        else {
          if(tmp<0) ++small;
          else return true;
        }
      }
      return false;
    }
};


int main() {
  auto solution = Solution();
  assert(solution.judgeSquareSum(5));
  return 0;
}
