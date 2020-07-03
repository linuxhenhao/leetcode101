#include <vector>
#include <iostream>

using namespace std;


class Solution {
  public:
    bool checkPossibility(vector<int>& nums) {
      int n = nums.size();
      if(n==1) return true;
      bool adjusted = false;
      int index = 0;
      for (int i=0;i<n-2;++i) {
        if(nums[i]>nums[i+1]) {
          if(adjusted) return false;
          else {
            adjusted = true;
            index = i;
          }
        }
      }
      if (index==0 or index==n-2 or )
    }
};


int main() {
    vector<int> a{2, 4, 2, 1}; 
    auto solution = Solution();
    cout<<solution.checkPossibility(a)<<endl;
    return 0;
}
