#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> partitionLabels(std::string S) {
        int str_size = S.size();
        std::vector<int> result;
        int map[26], i;
        for(i=0;i<str_size;++i) {
          map[(int)(S[i]-'a')] = i;
        }
        int anchor=0, stop=0, map_index;
        for(i=0;i<str_size;++i) {
          map_index = (int)(S[i]-'a');
          stop = map[map_index] > stop? map[map_index]:stop;
          if(stop == i) {
            result.push_back(stop-anchor+1);
            anchor = stop + 1;
          }
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
