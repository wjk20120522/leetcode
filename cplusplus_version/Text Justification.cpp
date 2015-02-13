/**
 * other people's method
 */
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans, vs;
        string str;
        int len = 0, div = 0, mod = 0;

        for (int i = 0; i < words.size(); ++i) {
            if (len + vs.size() + words[i].size() <= L) {   
                vs.push_back(words[i]);
                len += words[i].size();
            }
            else {
                if (vs.size() == 1) {    //special one word
                    str = vs[0];
                    str.append(L - str.size(), ' ');
                    ans.push_back(str);
                }
                else if (vs.size() > 1) {
                    div = (L - len) / (vs.size() - 1);
                    mod = (L - len) % (vs.size() - 1);
                    str = vs[0];
                    for (int j = 1; j < vs.size(); ++j) {
                        if (j <= mod) str.append(div+1, ' '); // one more space
                        else str.append(div, ' ');
                        str += vs[j];
                    }
                    ans.push_back(str);
                }

                vs.clear();
                vs.push_back(words[i]);
                len = words[i].size();
            }
        }

        // add the last line
        // left justified and no extra space is inserted between words
        str = vs[0];
        for (int i = 1; i < vs.size(); ++i) {
            str += ' ' + vs[i];
        }
        str.append(L-str.size(), ' ');
        ans.push_back(str);
        return ans;
    }
};