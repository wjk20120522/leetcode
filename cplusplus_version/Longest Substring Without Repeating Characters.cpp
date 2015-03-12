class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0, idx = 0;
        unordered_map<char, int> place;

        for(int i = 0; i<s.length(); i++) {
            if(place.find(s[i]) != place.end() && place[s[i]] >= idx) {   // see the s[i] before and it is behind the idx
                    idx = place[s[i]]+1;
            } else { 
                if(i-idx+1 > maxlen) maxlen = i-idx+1;
            }
            place[s[i]] = i;
        }
        return maxlen;
    }
};