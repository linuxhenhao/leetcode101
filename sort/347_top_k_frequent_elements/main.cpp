#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution {
  public:
    vector<int> topk(vector<int>& nums, int k) {
      unordered_map<int, int> count;
      int max_count=0;
      for(auto & item: nums) {
        max_count = max(max_count, ++count[item]);
      }
      vector<int> buckets(max_count+1);
      for(auto i=count.begin();i!=count.end();++i) {
        buckets[i->second]=i->first;
      }
      vector<int> result;
      for(int i=max_count;i>0 && result.size()<k; --i) {
        if(buckets[i]!=0) result.push_back(buckets[i]);
      }
      return result;
    }
};


int main() {
  vector<int> a{1, 1, 1, 1, 3, 3, 2}, a1={1, 3, 2};
  vector<int> b{3}, b1{3};
  vector<int> c{1, 1, 3, 3, 3, 5}, c1{3, 1};
  auto s=Solution();
  assert(s.topk(a, 3)==a1);
  assert(s.topk(b, 1)==b1);
  assert(s.topk(c, 2)==c1);
  return 0;

}
