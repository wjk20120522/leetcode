class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        char const * ss = NULL, *start = NULL;
        
        while(*s) {
            if(*p == '?' || *p == *s) { s++; p++; continue;}
            
            if(*p == '*') { start = p++; ss =s ; continue;}
            
            if(start) { s = ++ss;  p = start+1; continue; }
    
            return  false;
        }
        while(*p == '*') p++;
        
        return !*p;
    }
};