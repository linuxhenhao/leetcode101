#include <vector>
#include <cassert>
#include <string>

using namespace std;


class Solution {
  public:
    string frequencySort(string s) {
      vector<int> count(128);
      int max_count=0;
      for(auto & c: s) {
        max_count = max(max_count, ++count[int(c)]);
      }
      vector<vector<int>> order(max_count+1);
      for(int i=0;i<128;++i) {
        if (count[i]!=0) order[count[i]].push_back(i);
      }
      string result;
      int left_count;
      for(int i=max_count;i>0;--i) {
        for(auto &c: order[i]) {
          left_count = i;
          while(left_count--!=0) {
            result.push_back((char)c);
          }
        }
      }
      return result;
    }
};


int main() {
  string s("aaacccccdd"), s1("cccccaaadd");;
  string z("abcdd"), z1("ddabc");
  auto so=Solution();
  assert(so.frequencySort(s)==s1);
  assert(so.frequencySort(z)==z1);
  return 0;
}
