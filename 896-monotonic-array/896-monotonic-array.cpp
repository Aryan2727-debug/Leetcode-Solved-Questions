class Solution {
public:
    
    /*bool isIncreasing(vector<int>& v){
        for(int i=0;i<v.size();i++){
            if((v[v.size()-1] < v[v.size()-2]) || (v[v.size()-1] == v[v.size()-2])){
                return true;
            }
        }
        return false;
    }
    
    bool isDecreasing(vector<int>& v){
        for(int i=0;i<v.size();i++){
            if((v[v.size()-1] > v[v.size()-2]) || (v[v.size()-1] == v[v.size()-2])){
                return true;
            }
        }
        return false;
    }*/
    
    bool isMonotonic(vector<int>& nums) {
        if(std::is_sorted(std::begin(nums),
		std::end(nums), std::greater<int>()) || std::is_sorted(nums.begin(),
		nums.end())){
            return true;
        }
        return false;
    }
};