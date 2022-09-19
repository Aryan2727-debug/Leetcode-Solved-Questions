class Solution {
public:
    bool isPerfectSquare(int num) {
if(num==1){
return 1;
}
int low = 0;
int high = num-1;
while(low<=high){
int mid = low+(high-low)/2;
long long square = (long long) mid*mid;
if(square == (long long) num){
return 1;
}
else if(square < (long long) num){
low = mid+1;
}
else{
high = mid-1;
}
}
return 0;
}
};