bool binary(vector<int>&arr ,int k,int i){
    
    int low=0;
    int high=arr.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(k==arr[mid] && mid!=i){
            return true;
        }
        else if(arr[mid]<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return false;
}

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());   
        for(int i = 0 ; i < arr.size(); i++){
            if(binary(arr,(2*arr[i]),i)){
                return true;
            }
        }
        return false;
    }
};