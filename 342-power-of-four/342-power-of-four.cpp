class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        
        double a = log2(n) / log2(4);
        return int(a) == a;
    }
};