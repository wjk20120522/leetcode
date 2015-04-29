class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp, origin ;
        int len = (int) s.length();
        for(int i=0; i<len; i++) {
            if(origin.find(t[i]) != origin.end() && s[i] != origin[t[i]])     // can't map to same character
                return false;
            if(mp.find(s[i]) != mp.end() && mp[s[i]] != t[i])   // can't map to different characters
                return false;
            mp[s[i]] = t[i];
            origin[t[i]] = s[i];
        }
        return true;
    }
};