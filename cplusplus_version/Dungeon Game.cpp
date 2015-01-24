class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
         int m = dungeon.size();
		 int n = dungeon[0].size();
		 vector<vector<int> >  miniRem(m, vector<int>(n, 0));
		 for (int i = m - 1; i >= 0; i--) {
			 for (int j = n - 1; j >= 0; j--) {
				 if (i == m - 1 && j == n - 1) {
					 miniRem[i][j] = max(1, 1 - dungeon[i][j]);
				 }
				 else if (i == m - 1) {
					 miniRem[i][j] = max(1, miniRem[i][j + 1] - dungeon[i][j]);
				 }
				 else if (j == n - 1) {
					 miniRem[i][j] = max(1, miniRem[i + 1][j] - dungeon[i][j]);
				 }
				 else {
					 miniRem[i][j] = max(1, min(miniRem[i + 1][j], miniRem[i][j + 1])-dungeon[i][j]);
				 }
			 }
		 }
		 return miniRem[0][0];
    }
};