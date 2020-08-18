#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class Solution {
  public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int size = nums.size();
      if(!size) return {-1, -1};
      int l=0, r=size, mid, value; 
      bool found=false;
      while(l<r) {
        mid = l + (r-l)/2;
        value = nums[mid];
        if(value<target) {
          l = mid+1;
        } else {
          if(value>target) r = mid;
          else {
            found=true;
            break;
          }
        }
      }
      if(!found) return {-1, -1};
      int l1=l, r1=mid, l2=mid, r2=r;
      int left=mid, right=mid;
      while(l1<r1){
        mid = l1 + (r1-l1)/2;
        value = nums[mid];
        if(value == target) {
          left=mid;
          r1 = mid;
        } else {
          // value < target
          l1=mid+1;
        }
      }
      while(l2<r2) {
        mid = l2 + (r2-l2)/2;
        value = nums[mid];
        if(value == target) {
          right=mid;
          l2=mid+1;
        } else {
          // value > target
          r2 = mid;
        }
      }
      return {left, right};
    }
};


int main() {
  auto solution = Solution();
  vector<int> a{1, 2, 3, 3, 3, 5}, a1{2, 4};
  vector<int> b{2, 2, 2, 2}, b1{0, 3};
  vector<int> c{}, c1{-1, -1};
  vector<int> d{1}, d1{0, 0};
  assert(solution.searchRange(a, 3)==a1);
  cout<<"1passed"<<endl;
  assert(solution.searchRange(b, 2)==b1);
  cout<<"2passed"<<endl;
  assert(solution.searchRange(c, 1)==c1);
  cout<<"3passed"<<endl;
  assert(solution.searchRange(d, 1)==d1);
  cout<<"4passed"<<endl;
  return 0;
}
