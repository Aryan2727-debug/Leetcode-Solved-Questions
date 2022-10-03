class Solution {
public:
  int prefixCount(vector<string>& words, string pref) {
    int ans = 0, len = pref.length();
    for (int i = 0;i < words.size(); i++) {
      if (words[i].length() >= len) {
        if (words[i].substr(0, len) == pref)
          ans++;
      }
    }

    return ans;
  }
};