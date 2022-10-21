class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> v;           //declaring an empty vector
        
        for(int i=0;i<nums1.size();i++){           //putting elements of nums1 in v
            v.push_back(nums1[i]);
        }
        
        for(int i=0;i<nums2.size();i++){           //putting elements of nums2 in v
            v.push_back(nums2[i]);
        }
        
        sort(v.begin() , v.end());                 //sorting v
        
        int n = v.size(); 
        
        double median = (n%2) ? v[n/2] : (v[n/2-1] + v[n/2])/2.0;     //finding the median
        
        return median;
    }
};