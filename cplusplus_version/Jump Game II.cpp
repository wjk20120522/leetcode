class Solution {
public:
    int jump(int A[], int n) {
          int index = 0;

		 int jumps;
		 int max_index;
		 int steps = 0;
		 while (index < n - 1)
		 {
			 jumps = A[index];
			 int max = index + jumps;
			 for (int i = 1 + index; i <= jumps + index; i++)
			 {
				 if (i + A[i] > max)
				 {
					 max = i + A[i];
					 max_index = i;
				 } else if (i == n - 1){
					 max_index = n - 1;
				 }
			 }

			 index = max_index;
			 steps++;

		 }
		 return steps;
    }
};