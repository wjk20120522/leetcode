class Solution {
	 int *place;
	 int sp;
	 int count;
	 vector<vector<string> >res;
 public:
	 vector<vector<string> > solveNQueens(int n) {
		 place = new int[n];
		 sp = 0;
		 count = 0;
		 res.clear();
		 queens(0, 0, n);
		 
		 return res;
	 }

	 void push(int x)
	 {
		 place[sp] = x;
		 sp++;
	 }
	 int pop()//出栈   
	 {
		 if (sp == 0)    // 从第一行弹出，表示已经遍历完所有情形
		 {
			 return -1;
		 }
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

	 void output(int n) {
		 //可以输出对应样貌
		 vector<string>ll;
		 for (int k = 0; k < n; k++) {
			 string line;

			 for (int m = 0; m < n; m++) {
				 if (place[k] == m) {
					 line += "Q";
				 }
				 else {
					 line += ".";
				 }
			 }
			 ll.push_back(line);
		 }
		 res.push_back(ll);
	 }

	 void queens(int i, int j, int n)
	 {
		 
		 if (i >= n)
		 {
			 count++;
			 output(n);
			 
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