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
		if (sp == 0)
		{
			return -1;
		}
		return place[--sp];
	}
	int judge(int i, int j, int n)
	{
		if (j>n-1)
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
		if (i>n-1)
		{
			count++;
			j = pop();
			if (j == -1) return;
			queens(--i, ++j,n);
		}

		else if (judge(i, j,n ) == 1)   //这个位置不能放置皇后  
		{
			if (j >= n-1)
			{
				j = pop();
				if (j == -1) return;
				queens(--i, ++j,n);
			}
			else
			{
				queens(i, ++j,n);
			}

		}
		else                     //可以放置皇后  
		{
			push(j);
			queens(++i, 0,n );
		}
	}

};
