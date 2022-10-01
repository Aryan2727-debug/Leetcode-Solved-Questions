class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(m == 0)
        nums1 = nums2;
    else if (n > 0){
        int i = m - 1 , j = n - 1 , k = m + n - 1;
        while(i >= 0 && j >= 0){
            if(nums2[j] > nums1[i])
                nums1[k] = nums2[j--];
            else
                nums1[k] = nums1[i--];
            k--;
        }
        for(int i = j; i >= 0; i--)
            nums1[i] = nums2[i];
    }
}
};