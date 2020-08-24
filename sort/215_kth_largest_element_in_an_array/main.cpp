#include <vector>
#include <cassert>

using namespace std;

class Solution {
    void swap(vector<int>& nums, int l, int r) {
      int tmp=nums[l];
      nums[l]=nums[r];
      nums[r]=tmp;
    }

  public:
    int findKthLargest(vector<int>& nums, int k) {
      int size=nums.size();
      int l=0, r=size-1;
      int left, right, key;
      while(true) {
        left=l, right=r, key=nums[left];
        if(k==1) {
          int max=nums[l];
          for(int i=0;i<=r;++i) max=nums[i]>max?nums[i]:max;
          return max;
        }
        while(left<right) {
          while(left<right and key>nums[right]) --right;
          swap(nums, left, right);
          while(left<right and key<=nums[left]) ++left;
          swap(nums, left, right);
        }
        nums[left]=key;
        if(left-l==k-1) return nums[left];
        else {
          if(left-l<k-1) {
            k-=left-l+1;
            l=left+1;
          } else {
            r=left-1;
          }
        }
      }
    }
};


int main() {
  auto s=Solution();
  vector<int> nums{1, 3, 9, 2, 7, 5, 4};
  // 1, 2, 3, 4, 5, 7, 9
  assert(s.findKthLargest(nums, 1)==9);
  assert(s.findKthLargest(nums, 3)==5);
  return 0;
}
