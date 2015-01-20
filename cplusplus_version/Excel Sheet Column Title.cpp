class Solution {
public:
    string convertToTitle(int n) {
         string res;
		  char val;
		  while (n > 0) {
			  val = n % 26  + 'A' -1 ;
			  if (n % 26 == 0) {
				  val = 'Z';
				  n = n / 26 - 1;
			  }
			  else {
				  n /= 26;
			  }
			  res = val + res;	
		  }
		  return res;
    }
};