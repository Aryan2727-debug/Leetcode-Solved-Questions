class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int start = 0;         //starting index
        int end = 0;           //ending index

        int freq[3] = {0};     //array to store freq of each character

        while(end < s.size()){
            freq[s[end] - 'a']++;      //expanding the size of the window until all 3 characters are found

            while(freq[0] && freq[1] && freq[2]){
                count += s.size() - end;             //incrementing the count
                freq[s[start] - 'a']--;              //shrinking window size from left
                start++;
            }
            end++;
        }
        return count;
    }
};