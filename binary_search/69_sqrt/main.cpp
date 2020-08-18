#include <iostream>
#include <cassert>


using namespace std;


class Solution {
  public:
    int sqrt(int x) {
      if (x == 0) return 0;
      int l=1, r=x, sqrt, middle;
      while(l<=r) {
        middle = l + (r-l) / 2;
        sqrt = x / middle;
        if (sqrt > middle) {
          l = middle + 1;
        } else {
          if (sqrt < middle) {
            r = middle - 1;
          } else {
            return middle;
          }
        }
      }
      return r;
    }
};



int main() {
  auto solution = Solution();
  assert(solution.sqrt(1) == 1); 
  assert(solution.sqrt(3) == 1); 
  assert(solution.sqrt(10) == 3); 
  return 0;
}
