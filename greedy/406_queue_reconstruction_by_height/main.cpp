#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
              if (a[0] > b[0]) {
                return true;
              } else {
                if (a[0] < b[0]){
                  return false;
                } else {
                  return a[1] < b[1];
                }
              }
            });   
        for(auto &i: people) {
            result.insert(result.begin()+i[1], i);
        }
        return result;
    }
};


int main() {
  vector<vector<int>> people{{7,0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  auto solution = Solution();
  auto result = solution.reconstructQueue(people);
  for(auto &i: result) {
    cout<<i[0]<<i[1]<<endl;
  }
  return 0;
}

