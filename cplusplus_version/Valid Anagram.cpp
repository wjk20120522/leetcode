class Solution {
public:
    bool isAnagram(string s, string t) {
        int chars[26];
        memset(chars, 0, sizeof(chars));
        for(int i=0; i<s.length(); i++) {
            chars[s[i]-'a'] ++;
        }
        for(int i=0; i<t.length(); i++) {
            chars[t[i]-'a'] --;
        }
        for(int i=0; i<26; i++) {
            if(chars[i] != 0) return false;
        }
        return true;
    }
};