#include <string>
#include <vector>
#include <iostream>
#include <climits>

class Solution {
public:
    std::vector<int> partitionLabels(std::string S) {
        size_t size = S.size();
        std::vector<int> result;
        if (size < 2) {
          result.push_back(1);
          return result;
        }
        unsigned char map[26];
        unsigned char index, vector_index;
        std::vector<std::vector<int>> segments;
        for(int i=0; i<26; ++i) {
          map[i] = 255;
        }
        for(size_t i=0; i < size; ++i) {
          index = (unsigned char)(S[i] - 'a');
          vector_index = map[index];
          if (vector_index == 255) {
            map[index] = segments.size();
            std::vector<int> tmp{static_cast<int>(i), 0};
            segments.push_back(tmp);
          } else {
            segments[vector_index][1] = i;
          }
        }
        int start = INT_MAX;
        int end = INT_MAX;
        int s_size = segments.size();
        if (s_size == 1) {
          result.push_back(end+1);
          return result;
        }
        for(int i=0; i<s_size; ++i) {
          if (start == INT_MAX) {
              start = segments[i][0];
              end = segments[i][1];
              if (end == 0) {
                result.push_back(1);
                start = INT_MAX;
              }
              continue;
          }
          if (segments[i][0] > end) {
            result.push_back(end-start+1);
            start = end = INT_MAX;
            --i;
          } else  {
            end = segments[i][1] > end ? segments[i][1] : end;
          }
        }
        if (start != INT_MAX) {
          result.push_back(end-start+1);
        }
        return result;
    }
};


int main() {
  //std::string s{"aaa"};
  std::string s{"ababcbacadefegdehijhklij"};
  auto so = Solution();
  for (auto i: so.partitionLabels(s)) {
      std::cout<<i<<std::endl;
  }
  return 0;
}
