class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1;
        int current = m+n-1;
        while (current > -1) {
            if(i==-1 or j==-1) {
                break;
            }
            if (nums1[i]<nums2[j]) {
                nums1[current] = nums2[j];
                --j;
                --current;
            } else {
                nums1[current] = nums1[i];
                --i;
                --current;
            }
        }
        if(i==-1) {
            while(j!=-1) {
                nums1[current] = nums2[j];
                --current;
                --j;
            }
        } 
    }
};
