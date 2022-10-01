class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            string s = words[i];
            reverse(words[i].begin() , words[i].end());
            if(words[i] == s){
                return words[i];
            }
        }
        return "";
    }
};