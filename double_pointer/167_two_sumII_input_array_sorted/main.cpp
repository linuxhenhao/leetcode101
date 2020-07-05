class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1, value;
        while(i<j) {
            value = numbers[i] + numbers[j];
            if (value < target) {
                ++i;
            } else {
                if (value > target) {
                    --j;
                } else {
                    return vector<int>{i+1, j+1};
                }
            }
        }
        return vector<int>{0, 0};
    }
};

