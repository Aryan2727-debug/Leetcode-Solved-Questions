class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int boomerangs = 0;

        unordered_map<int, int> mp;

        for(int i=0; i<p.size() ; i++){
            for(int j=0 ; j<p.size() ; j++){
                int x = pow(p[j][1] - p[i][1], 2) + pow(p[j][0] - p[i][0], 2);
                boomerangs += 2 * mp[x]++;
            }
            mp.clear();
        }
        return boomerangs;
    }
    
};