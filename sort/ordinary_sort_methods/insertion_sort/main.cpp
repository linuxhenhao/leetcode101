#include <vector>
#include <cassert>
#include <iostream>


using namespace std;


void swap(vector<int>& nums, int l, int r) {
  int tmp=nums[l];
  nums[l]=nums[r];
  nums[r]=tmp;
}


void insertion_sort(vector<int>& nums, int n) {
  if (n<=1) return;
  for(int i=1;i<n;++i) {
       for(int j=i;j>0;--j) {
          if(nums[j-1]>nums[j]) swap(nums, j, j-1);
          else break;
       } 
  }
}

int main() {
  vector<int> a{9, 7, 3, 1, 5, 4, 8}, sorted{1, 3, 4, 5, 7, 8, 9};
  insertion_sort(a, a.size());
  assert(a==sorted);
  return 0;
}
