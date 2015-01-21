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