#include <vector>
#include <cassert>

using namespace std;


void merge_sort(vector<int>& nums, int start, int stop, vector<int>& temp) {
  if(stop-start<2) return;
  int mid=start+(stop-start)/2;
  merge_sort(nums, start, mid, temp);
  merge_sort(nums, mid, stop, temp);
  int p=start, q=mid, i=start;
  while(i<stop) {
    if(p>=mid or (q<stop and nums[q]<nums[p]))
      temp[i++]=nums[q++];
    else
      temp[i++]=nums[p++];
  }
  for(i=start;i<stop;++i) {
    nums[i]=temp[i];
  }
}


int main() {
  vector<int> nums{21, 9, 83, 7, 42, 19, 8317}, sorted{7, 9, 19, 21, 42, 83, 8317};
  vector<int> temp(nums.size());
  merge_sort(nums, 0, nums.size(), temp);
  assert(nums==sorted);
  return 0;
}
