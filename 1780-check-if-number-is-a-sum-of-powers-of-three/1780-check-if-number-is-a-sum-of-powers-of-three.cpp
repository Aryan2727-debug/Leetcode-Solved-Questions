class Solution {
public:
    bool checkPowersOfThree(int n) {
        if(n <= 3)
            if(n == 1 or n == 3)
                return true;
            else
                return false;
        if(n % 3 == 2)
           return false;
        else
            return checkPowersOfThree(n/3);
    }
};