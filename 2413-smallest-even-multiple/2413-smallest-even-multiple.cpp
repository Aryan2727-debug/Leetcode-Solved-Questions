class Solution {
public:
    int smallestEvenMultiple(int n) {
        int max = INT_MAX;
        for(int i=2;i<=max;i++){
            if(i%2 == 0 && i%n == 0){
                return i;
                break;
            }
        }
        return -1;
    }
};