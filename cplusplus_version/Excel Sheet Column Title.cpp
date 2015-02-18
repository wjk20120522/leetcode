class Solution {
public:
    string convertToTitle(int n) {
    	string res;
		while (n) {
			if (n % 26 == 0) {
				res = 'Z' + res;
				n--;
			}
			else {
				res = char('A' + n%26-1) + res;
			}
			n /= 26;
		}
    }
};
/* shorter...
string convertToTitle(int n) {
	string res;
	while (n) {	
		res = char('A' + (n-1)%26) + res;
		n = (n-1)/26;
	}
	return res;
}
*/
		


