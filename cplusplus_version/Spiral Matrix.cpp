class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
         vector<int>res;
		 int rows = matrix.size();
		 if (rows == 0) return res;
		 int cols = matrix[0].size();
		 res.resize(rows*cols);
		 int all = rows*cols;
		 int index = 0,i=0, j=0;
		 int rownum = rows, colnum = cols;
		 while (index < all) {
			 // right
			 for (int k = 0; k<colnum && index<all; j++,k++) {
				 res[index++] = matrix[i][j];
			 }
			 rownum--; colnum--;  i++; j--;
			 //down
			 for (int k = 0; k < rownum && index<all; i++,k++) {
				 res[index++] = matrix[i][j];
			 }
			 i--; j--;
			 //left
			 for (int k = 0; k < colnum && index < all; j--,k++) {
				 res[index++] = matrix[i][j];
			 }
			 rownum--; colnum--;  j++; i--;
			 //up
			 for (int k = 0; k < rownum && index < all; i--, k++) {
				 res[index++] = matrix[i][j];
			 }
			 i++; j++;
		 }
		 return res;
    }
};