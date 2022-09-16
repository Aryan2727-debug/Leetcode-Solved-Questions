class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int x = n;
        while(n>0){
            sum = sum + (n%10);
            n = n/10;
        }
        
        int product = 1;
        while(x>0){
            product = product * (x%10);
            x = x/10;
        }
        return product-sum;
    }
};