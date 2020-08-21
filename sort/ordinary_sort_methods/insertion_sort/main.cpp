#include <vector>
#include <cassert>

using namespace std;

void swap(vector<int>& nums, int l, int r) {
  int tmp=nums[l];
  nums[l]=nums[r];
  nums[r]=tmp;
}


void insertion_sort(vector<int>& nums, int n) {
  if(n<2) return;
  for(int i=1; i<n; ++i) {
    for(int j=i; j>0 and nums[j-1]>nums[j]; --j) 
      swap(nums, j, j-1);
  } 
}


int main() {
  vector<int> a{3, 5, 1, 9, 7, 6}, sorted{1, 3, 5, 6, 7, 9};
  insertion_sort(a, a.size());
  assert(a==sorted);
  return 0;
}
