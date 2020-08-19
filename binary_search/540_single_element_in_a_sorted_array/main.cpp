#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
  public:
    int singleNonDuplicate(vector<int>& nums) {
      int size = nums.size();
      int l=0, r=size, mid, value;
      while(l<r){
        mid = l+(r-l)/2;
        value = nums[mid];
        if(mid-1>=0 and value==nums[mid-1]) {
          if(mid%2==0) r=mid;
          else l=mid+1;
        } else {
          if(mid+1<size and value == nums[mid+1]) {
            if(mid%2==0) l=mid+2;
            else r=mid;
          } else {
            return value;
          }
        }
      }
      return 0;
    }
};


int main() {
  auto s = Solution();
  vector<int> a{1}; int a1=1;
  vector<int> b{1, 1, 3, 4, 4}; int b1=3;
  vector<int> c{1, 1, 4, 4, 5}; int c1=5;
  vector<int> d{1, 1, 2, 2, 4, 5, 5, 6, 6}; int d1=4;
  assert(s.singleNonDuplicate(a)==a1);
  assert(s.singleNonDuplicate(b)==b1);
  assert(s.singleNonDuplicate(c)==c1);
  assert(s.singleNonDuplicate(d)==d1);
  return 0;
}
