class Solution {
public:
    int dp[101];                        //initilazing a dp array
    
    int solve(int index, string &s ) {
        
        //if index value is greater than string length, return
        
        if(index > s.length()) {         
            return 0; 
        }
        
        //if index value is eqaul to string length, there is only 1 way to decode the string
        
        if(index == s.length())         
            return 1; 
        
        //if 1st character of string is 0, case is invalid
        
        if(s[index] == '0') 
            return 0;   
        
        
        if(dp[index] != -1) 
            return dp[index]; 
        
        int curr_num1 = stoi(s.substr(index, 1)); 
        int curr_num2 = stoi(s.substr(index, 2));  
        
        int one = 0;  
        int two = 0;  
        if(curr_num1 >= 1 && curr_num1 <= 9) {
            one = solve(index + 1, s); 
        }
        if(curr_num2 >= 10 && curr_num2 <= 26) {
            two = solve(index + 2, s); 
        }
        
        return dp[index] = one + two; 
    }
    
    
    int numDecodings(string s) {
        memset(dp, -1, sizeof dp);   
        return solve(0, s); 
    }
};