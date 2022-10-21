class Solution {
public:
    bool checkPerfectNumber(int num) {
        vector<int> numbers = {6 , 28 , 496 , 8128 , 33550336};
        
        for(int i=0;i<numbers.size();i++){
            if(num == numbers[i]){
                return true;
            }
        }
        return false;
    }
};