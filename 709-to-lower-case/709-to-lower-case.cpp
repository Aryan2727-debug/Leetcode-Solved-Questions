class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.length();i++){
            for(int j=65;j<=90;j++){
                if(s[i] == j){
                    s[i] = tolower(s[i]);
                }
            }
        }
        return s;
    }
};