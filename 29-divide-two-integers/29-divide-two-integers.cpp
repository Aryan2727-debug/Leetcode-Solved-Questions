class Solution {
public:
    int divide(int dividend, int divisor) {
//	check edge case when both dividends and divisor are INT_MIN  to avoid integer overflow provlem //
        if(dividend==divisor) return 1;  
       unsigned int ans=0;
	//   here we taking both numbers as positive//
       unsigned int a =abs(dividend);
       unsigned int b =abs(divisor);
        int neg=0;
		//so if our numbers are opposite sign so we have handle that cases also//
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)) {          
             neg=1;
        }       
	//using bit manipulation property that 1 left shift operator multiply our number by 2//
        while(a>=b){
            short i=0;
            while(a>(b<<(i+1))) i++;                
            a= a-(b<<i);
            ans+=(1<<i);    
        }
        if(ans>=INT_MAX){
             if(neg==1  ) {
                return INT_MIN;
              }
             return INT_MAX;
        }
        if(neg==1  ) {
            return -ans;
        }       
        return ans;
        
    }
};