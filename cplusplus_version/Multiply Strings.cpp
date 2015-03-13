/*
simple and clear code
 */
string multiply(string num1, string num2) {
    string sum(num1.size() + num2.size(), '0');

    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }

    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";
}


class Solution {
public:
    string multiply(string num1, string num2) {
         int L1 = num1.length(), L2 = num2.length();
		 if (L1 * L2 == 0) return "0";
		 vector<int>res(L1 + L2, 0);
		 int i_n1 =0, i_n2;   // index of num1 and num2
		 for (int i = L1-1; i >=0; i--) {
			 int n1 = num1[i] - '0';   

			 i_n2 = 0; int carry = 0;

			 for (int j = L2 - 1; j >= 0; j--) {
				 int n2 = num2[j] - '0';
				 carry = n1*n2 + carry + res[i_n1 + i_n2];
				 res[i_n1 + i_n2] = carry % 10;
				 carry = carry / 10;
				 i_n2++;
			 }
			 //the most left bit is big
			 if (carry) {
				 res[i_n1 + i_n2] = carry;
			 }
			 i_n1++;
		 }
		 
		 int index = L1 + L2 - 1;
		 while (index >= 0 && res[index] == 0 ) index--;
		 if (index == -1) return "0";    // the result is 0
		 string str;
		 for (; index >= 0; index--) {
			 str += to_string(res[index]);
		 }
		 return str;
    }
};


/*
similar like above, but in different direction
 */
class Solution {
public:
	string multiply(string num1, string num2) {
		int len1 = num1.length(), len2 = num2.length();
		if (len1 == 0 || len2 == 0 || (num1.length() == 1 && num1[0] == '0') || (num2.length() == 1 && num2[0] == '0')) return "0";
		vector<int> res(len1 + len2,0);
		string ret;
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				res[i + j] += (num1[i] - '0')*(num2[j] - '0');
			}
		}
		for (int i = 0; i < len1 + len2; i++) {
			if (res[i] >= 10) {
				res[i + 1] += res[i] / 10;
				res[i] = res[i] % 10;
			}
		}
		int idx = len1 + len2 - 1;
		while (idx >=0 && res[idx] == 0) idx--;
		while (idx >= 0) {
			ret += to_string(res[idx--]);
		}
		return ret;
	}
};