class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        vector<int>ans;
        
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->first == it->second) {
                ans.push_back(it->first);
            }
        }
        if(ans.size() == 0)
            return -1;
        else{
            sort(ans.begin(), ans.end());
            return ans[ans.size()-1];
        } 
            
    }
};