class Solution {
public:
    string addBinary(string a, string b) {
        string res;
		 int tmp, carry = 0;
		 int lena = a.length(), lenb = b.length();
		 while (lena || lenb) {
			 int vala = lena ? a[lena - 1] - '0' : 0;
			 int valb = lenb ? b[lenb - 1] - '0' : 0;
			 tmp = vala + valb + carry;
			 res = to_string(tmp % 2) + res;
			 carry = tmp >= 2 ? 1 : 0;
			 lena = lena > 0 ? lena - 1 : 0;
			 lenb = lenb > 0 ? lenb - 1 : 0;
		 }
		 if (carry) res = "1" + res;
		 return res;
    }
};