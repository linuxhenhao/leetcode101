#include <vector>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
  public:
    string findLongestWord(string s, vector<string>& d) {
        int s_size = s.size();
        if (s_size == 0) return string("");
        int s_index, word_index, word_size, vector_index=-1, max_len=0;
        string word;
        char s_c, word_c;
        bool not_matched;
        for(int i=0; i<d.size(); ++i) {
          word = d[i];
          word_size = word.size();
          if(word_size == 0) continue;
          s_index=word_index=0;
          not_matched=false;
          while(s_index<s_size and word_index<word_size) {
            s_c = s[s_index];
            word_c = word[word_index];
            if(s_c == word_c) ++s_index && ++word_index;
            else ++s_index;
            if(s_size-s_index < word_size-word_index){
              not_matched=true;
              break;
            }
          }
          if(!not_matched) {
            if(word_size>max_len or (word_size==max_len and word < d[vector_index])) {
              max_len = word_size;
              vector_index = i;
            }
          }
        }
        if(vector_index==-1) return string("");
        return d[vector_index];
    }
};


int main() {
  vector<string> d{{"c", "b", "a"}};
  string s{"abc"};
  auto solution = Solution();
  assert(solution.findLongestWord(s, d)==string("a"));
  return 0;
}
