#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class Solution {
  public:
  bool search(vector<int>& nums, int target) {
    int size = nums.size();
    if(!size) return false;
    int l=0, r=size-1, mid, value;
    while(l<=r) {
      mid = l + (r-l)/2;
      value = nums[mid];
      if(value==target) return true;
      if(value==nums[l]) ++l;
      else {
        if(value<=nums[r]) {
          if(target>value and target<=nums[r]) l=mid+1;
          else r=mid-1;
        } else {
          if(target<value and target>=nums[l]) r=mid-1;
          else l=mid+1;
        }
      }
    }
    return false;
  }
};


int main() {
  auto solution = Solution();
  vector<int> a{3, 4, 5, 1, 2}; int a1=4; bool a1_r=true;
  vector<int> b{1, 1, 1, 1, 1, 1}; int b1=2; bool b1_r=false;
  vector<int> c{1, 1, 1, 1, 2, 1}; int c1=2; bool c1_r=true;
  vector<int> d{1, 2, 1, 1, 1, 1}; int d1=2; bool d1_r=true;
  assert(solution.search(a, a1)==a1_r);
  assert(solution.search(b, b1)==b1_r);
  assert(solution.search(c, c1)==c1_r);
  assert(solution.search(d, d1)==d1_r);
  return 0;
}
