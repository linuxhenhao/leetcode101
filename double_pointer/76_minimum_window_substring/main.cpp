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
        auto flags=vector<bool>(128, false);
        auto target=vector<int>(128, 0);
        for(char c: t) {
            flags[c] = true;
            target[c]+=1;
        }
        char c;
        auto skip_vector = vector<pair<int, char>>(); 
        for(int i=0; i<s_size; ++i) {
            c = s[i];
            if(flags[c]){
                skip_vector.push_back(make_pair(i, c));
            }
        }
        
        int size = skip_vector.size();
        int cnt = 0;
        int l=0, r=0, start=-1, end=-1, len=INT_MAX;
        while(r<size) {
            c = skip_vector[r].second;
            
            if(--target[c] >= 0) {
                ++cnt;
            }
        
            while(l<=r and cnt == t.size()) {
                if (len > skip_vector[r].first - skip_vector[l].first) {
                    start = skip_vector[l].first;
                    end = skip_vector[r].first;
                    len = end - start + 1;
                }
                c = skip_vector[l].second;
                
                if(++target[c] > 0) {
                    --cnt;
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
