#include <vector>
#include <cassert>

using namespace std;

void swap(vector<int>& nums, int l, int r) {
  int tmp=nums[l];
  nums[l]=nums[r];
  nums[r]=tmp;
}


void selection_sort(vector<int>& nums, int n) {
  if(n<2) return;
  int min, i, j;
  for(i=0;i<n-1;++i){
    min=i;
    for(j=i+1;j<n;++j) {
      if(nums[min]>nums[j]) min=j;
    }
    swap(nums, i, min);
  }
}

int main() {
  vector<int> a{112, 22, 15, 1, 7, 22}, sorted{1, 7, 15, 22, 22, 112};
  selection_sort(a, a.size());
  assert(a==sorted);
  return 0;
}
