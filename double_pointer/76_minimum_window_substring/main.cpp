#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <climits>
#include <iostream>

using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        int t_size = t.size();
        int s_size = s.size();
        if(!t_size or !s_size) return string("");
        auto target_map = unordered_map<char, int>();
        auto window_map = unordered_map<char, int>();
        auto skip_vector = vector<pair<int, char>>();
        char c;
        for(char c: t) {
          if(target_map.find(c) != target_map.end()) {
              target_map[c] += 1;
          } else {
              target_map[c] = 1;
          }
        }
        for(int i=0;i<s_size; ++i) {
          c = s[i];
          if(target_map.find(c) != target_map.end()) {
            skip_vector.push_back(make_pair(i, c));
          }
        }
        int required = target_map.size();
        int size = skip_vector.size();
        int formed=0, l=0, r=0, start=-1, end=-1, len=INT_MAX;
        while(r<size) {
          c = skip_vector[r].second;
          if(window_map.find(c) != window_map.end()) {
            window_map[c] += 1;
          } else {
            window_map[c] = 1;
          }
          if(window_map[c] == target_map[c]) ++formed;
          while(l<=r and required==formed) {
            if(len>skip_vector[r].first - skip_vector[l].first) {
              start = skip_vector[l].first;
              end = skip_vector[r].first;
              len = end - start + 1;
            }
            c = skip_vector[l].second;
            window_map[c] -= 1;
            if(window_map[c] < target_map[c]) {
              --formed;
            }
            ++l;
          }
          ++r;
        }
        if(start == -1) return string("");
        return s.substr(start, len);
    }
};


int main() {
  string s = string("ADOBECODEBANC");
  string t = string("ABC");
  //string s = string("A");
  //string t = string("A");

  auto solution = Solution();
  cout<<solution.minWindow(s, t)<<endl;
  return 0;
}
