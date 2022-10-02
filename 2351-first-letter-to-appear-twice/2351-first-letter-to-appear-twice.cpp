class Solution {
public:
char repeatedCharacter(string s) {

	char c;
   unordered_map<char,int> m;
    for(int i=0;i<s.size();i++){
        m[s[i]]++;
         if(m[s[i]]==2){
            c= s[i];
            break;
        }
    }
    return c;
}
};