#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
  public:
    bool checkPossibility(vector<int>& nums) {
            int index = 10E4+1;
            bool adjusted = false;
            int n = nums.size();
            if (n==1) return true;
            for(int i=0;i<n-1;++i) {
              if (nums[i] > nums[i+1]) {
              if (adjusted) return false;
              else {
                adjusted = true;
                index = i;
              }
             }
            }
            if (index != 10E4+1)
                return (index==0 or index==n-2 or (nums[index-1]<=nums[index+1]) or (nums[index]<=nums[index+2]));
            
            return true;
    }
};


int main() {
  vector<int> nums{4, 2, 3};
  auto solution = Solution();
  assert(solution.checkPossibility(nums));
  return 0;
}
