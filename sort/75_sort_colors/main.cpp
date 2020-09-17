#include <vector>
#include <cassert>

using namespace std;


class Solution{
    void swap(vector<int>& nums, int l, int r) {
      int tmp=nums[l];
      nums[l]=nums[r];
      nums[r]=tmp;
    }
  public:
    void sortColors(vector<int>& nums) {
      int p0=0, p2=nums.size()-1, cur=0;
      while(cur<=p2) {
        if(nums[cur]==0) {
          if(cur==p0) ++cur and ++p0;
          else {
            swap(nums, p0, cur);
            ++p0;
          }
        } else {
          if(nums[cur]==2) {
            swap(nums, cur, p2);
            --p2;
          } else ++cur;
        }
      }
    }
};


int main() {
  vector<int> a{1, 1, 0, 2, 1, 0, 2, 2}, a1{0, 0, 1, 1, 1, 2, 2, 2}; 
  vector<int> b{1}, b1{1};
  auto s=Solution();
  s.sortColors(a);
  s.sortColors(b);
  assert(a==a1);
  assert(b==b1);
  return 0;
}
