class Solution {
public:
    bool isPalindrome(string s) {
	    if( 0 == s.length()) {
			return true;
		}
		int i,j;
		for(i=0,j=s.length()-1; i<j; i++,j--) {
			//filter the non-alnum
			while(!isalnum(s[i])) {
				i++;
				//avoid endless loop
				if(i>s.length()-1) {
					break;
				}
			}
			while(!isalnum(s[j])) {
				j--;
				//avoid endless loop
				if(j<0) {
					break;
				}
			}
			if(i>=j) {
				break;
			}
			//compare the two characters
			if(isdigit(s[i]) || isdigit(s[j]) ) {
				if(s[i] != s[j] ) {
					return false;
				}
			} else {
				if(tolower(s[i]) != tolower(s[j])) {
					return false;
				}
			}
		}
		return true;
    }
};