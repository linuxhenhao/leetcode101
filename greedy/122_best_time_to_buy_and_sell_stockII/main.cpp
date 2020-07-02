#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      if (n==1) return 0; 
      int pre = prices[0];
      int profit = 0, delta;
      for(int i=0;i<n;++i){
        delta = prices[i] - pre;
        if (delta > 0) profit += delta; 
        pre = prices[i];
      }
      return profit;
    }
};


int main() {
  vector<int> prices{7, 1, 5, 3, 6, 4};
  auto solution = Solution();
  cout<<solution.maxProfit(prices)<<endl;
  return 0;
}
