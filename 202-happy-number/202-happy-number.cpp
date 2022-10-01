class Solution {
public:
    bool isHappy(int n) {
    int digit, sum = 0;

    while (n > 0)
    {
        sum = sum + (n%10)*(n%10);
        n = n / 10;

        if (n == 0) {
            if (sum == 1) {
                return true;
            }

            if (sum == 89) {
                break;
            }

            n = sum;
            sum = 0;
        }
    }

    return false;
}
};