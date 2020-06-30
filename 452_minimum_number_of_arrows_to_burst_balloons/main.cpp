#include <vector>
#include <iostream>
#include <algorithm>


class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        std::ios::sync_with_stdio(false);
        int size = points.size();
        if (size < 2) return size;
        sort(points.begin(), points.end(), [](std::vector<int>& a, std::vector<int>& b) { return a[0] < b[0];});
        int next = points[0][1];
        int n = 1;
        int candidate;
        for(int i=1; i < size; ++i) {
            if (points[i][0] > next) {
                ++n;
                next = points[i][1];
            } else {
                // constrain next
                candidate = points[i][1];
                next = candidate < next ? candidate : next;
            } 
        }
        return n;
    }
};


int main() {
    std::vector<std::vector<int>> input = {{3, 9}, {7, 12}, {3, 8}, {6, 8}, {9, 10}, {2, 9}, {0, 9}, {3, 9}, {0, 6}, {2, 8}};
    auto s = Solution();
    int r = s.findMinArrowShots(input);
    std::cout<<r<<std::endl;
    return 0;
}
