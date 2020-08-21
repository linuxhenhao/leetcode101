#include <vector>
#include <cassert>

using namespace std;

void swap(vector<int>& nums, int l, int r) {
  int tmp=nums[l];
  nums[l]=nums[r];
  nums[r]=tmp;
}


void quick_sort(vector<int>& nums, int start, int stop) {
  if(stop-start<2) return;
  int l=start, r=stop-1, key=nums[l];
  while(l<r) {
    while(l<r and key<=nums[r]) --r;
    swap(nums, l, r);
    while(l<r and key>nums[l]) ++l;
    swap(nums, l, r);
  }
  nums[l]=key;
  quick_sort(nums, start, l);
  quick_sort(nums, l+1, stop);
}


int main() {
  vector<int> a{3, 5, 1, 7, 9, 10, 33}, sorted{1, 3, 5, 7, 9, 10, 33};
  quick_sort(a, 0, a.size());
  assert(a==sorted);
  return 0;
}
