class Solution {
public:
    
    //function to find the GCD of an Array
    int findGcd(vector<int> &numsDivide){
        int gcd = numsDivide[0];

        for(int i=1;i<numsDivide.size();i++){
            int num = numsDivide[i];

            while(num > 0){
                int temp = gcd % num;
                gcd = num;
                num = temp;
            }
        }
        return gcd;
    }

    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcd = findGcd(numsDivide);

        sort(nums.begin() , nums.end());

        for(int i=0;i<nums.size();i++){
            if(gcd % nums[i] == 0){
                return i;
            }
        }
        return -1;
    }
};