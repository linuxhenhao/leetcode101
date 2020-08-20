#include <vector>
#include <cassert>

using namespace std;


class Solution {
    void swap(vector<int>& nums, int l, int r) {
      int tmp=nums[l];
      nums[l]=nums[r];
      nums[r]=tmp;
    }

    int findKthLargest(vector<int>& nums, int l, int r, int kth) {
      while(true) {
        if(kth==1) {
          int min=nums[l];
          for(int i=l;i<=r;++i) {
            min=nums[i]<min?nums[i]:min;
          }
          return min;
        }
        int left=l, right=r, key=nums[l];
        while(left<right) {
          while(left<right and key<=nums[right]) --right;
          swap(nums, left, right);
          while(left<right and key>nums[left]) ++left;
          swap(nums, left, right);
        }
        nums[left]=key;
        if(left-l==kth-1) return key;
        else {
          if(left-l<kth-1) {
            kth-=left-l+1;
            l=left+1;
          } else {
            r=left-1;
          }
        }
      }
    }
  public:
    int findKthLargest(vector<int>& nums, int kth) {
      int size=nums.size();
      int l=0, r=size-1;
      return findKthLargest(nums, l, r, kth);
    }
};


int main() {
  auto s=Solution();
  vector<int> nums{5, 4, 3, 2, 1, 7, 9, 8};
  assert(s.findKthLargest(nums, 1)==1);
  assert(s.findKthLargest(nums, 4)==4);
  assert(s.findKthLargest(nums, 7)==8);
  return 0;
}
