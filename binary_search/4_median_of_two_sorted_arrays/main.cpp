#include<vector>
#include<cassert>
#include<iostream>
#include<cmath>

using namespace std;


class Solution {
    int findKth(vector<int>& nums1, vector<int>& nums2, int kth) {
      int size1=nums1.size(), size2=nums2.size(), index1=0, index2=0, newIndex1, newIndex2;
      while(true) {
        if(index1==size1) {
          return nums2[index2+kth-1];
        }
        if(index2==size2) {
          return nums1[index1+kth-1];
        }
        if(kth==1) {
          return min(nums1[index1], nums2[index2]);
        }
        newIndex1 = min(size1-1, index1+kth/2-1);
        newIndex2 = min(size2-1, index2+kth/2-1);
        if(nums1[newIndex1]<=nums2[newIndex2]) {
          kth -= (newIndex1 - index1 +1);
          index1 = newIndex1+1;
        } else {
          kth -= (newIndex2 - index2 + 1);
          index2 = newIndex2+1;
        }
      }
    }
  public:
    double findMedian(vector<int>& nums1, vector<int>& nums2) {
      int total_size = nums1.size() + nums2.size();
      if (total_size%2==1) {
        return (double)findKth(nums1, nums2, total_size/2+1);
      } else {
        return (findKth(nums1, nums2, total_size/2) + findKth(nums1, nums2, total_size/2+1))/2.0;
      }
    }
};


int main() {
  auto s = Solution();
  vector<int> n1{}, n2{1, 2, 3}; double n_r=2;
  vector<int> k1{1, 2, 5}, k2{3, 4, 7}; double k_r=3.5;
  vector<int> j1{1, 2, 3}, j2{7, 8, 9, 10, 11}; double j_r=7.5;
  double e = 0.00001;
  cout<<s.findMedian(k1, k2)<<endl;
  assert(abs(s.findMedian(n1, n2)-n_r)<e);
  assert(abs(s.findMedian(k1, k2)-k_r)<e);
  assert(abs(s.findMedian(j1, j2)-j_r)<e);
  assert(abs(s.findMedian(j2, j1)-j_r)<e);
  return 0;
}
