class Solution {
	 int *place;
	 int sp;
	 int count;

 public:
	 int totalNQueens(int n) {
		 place = new int[n];
		 sp = 0;
		 count = 0;
		 
		 queens(0, 0, n);
		 
		 return count;
	 }

	 void push(int x)
	 {
		 place[sp] = x;
		 sp++;
	 }
	 
	 int pop()//出栈   
	 {
		 return place[--sp];    
	 }
	 
	 int judge(int i, int j, int n)
	 {
		 if (j>=n)    //已经遍历完该行
			 return 1;
	 
		 for (int k = i - 1; k >= 0; k--)
		 {
			 
			 if (j == place[k])//对角线，同列，斜对角线   
				 return 1;
			 if (i - k == j - place[k])
				 return 1;
			 if (i - k == place[k] - j)
				 return 1;
		 }
		 return 0;
	 }

	 
	 void queens(int i, int j, int n)
	 {
		 
		 if (i >= n)
		 {
			 count++;
		 }

		 for (int k = j; k < n; k++) {
			 if (judge(i, k, n) == 0) {
				 push(k);
				 queens(i+1, 0, n);
				 pop();
			 }
		 }
		
	 }

 };