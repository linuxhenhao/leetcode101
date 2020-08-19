#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class Solution {
  public:
    int findMin(vector<int>& nums) {
      int size = nums.size();    
      int l=0, r=size-1, mid, value, min=nums[0];
      while(l<=r) {
        mid = l+(r-l)/2;
        value = nums[mid];
        if(value==nums[l]) {
          min=value>min?min:value;
          ++l;
        } else {
          if(value<=nums[r]) {
            if(value < min) min=value;
            r = mid-1;
          } else {
            // mid_value > last && l->mid asc, min must be in other part
            l = mid+1;
          }
        }
      }
      return min;
    }
};


int main() {
  auto s=Solution();
  vector<int> a{1}; int a1=1;
  vector<int> b{2, 5, 7, 8, 1, 3}; int b1=1;
  vector<int> c{1, 1, 1, 1, 1}; int c1=1;
  vector<int> d{1, 1, 1, 3, 4, 1, 1}; int d1=1;
  assert(s.findMin(a)==a1);
  assert(s.findMin(b)==b1);
  assert(s.findMin(c)==c1);
  assert(s.findMin(d)==d1);
  return 0;

}

