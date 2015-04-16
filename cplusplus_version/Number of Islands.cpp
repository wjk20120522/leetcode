class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int lands = 0;
        rows = (int)grid.size();
        if(rows == 0) return 0;
        cols = (int)grid[0].size();

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == '1') {
                    lands++;
                    flood(grid, i, j);
                }
            }
        }
        return lands;
    }

private:
    int rows;
    int cols;

    void flood(vector<vector<char>> &grid, int i, int j) {
        grid[i][j] = '0';
        if(i>0 && grid[i-1][j] == '1') flood(grid, i-1,j);
        if(i<rows-1 && grid[i+1][j] == '1') flood(grid, i+1, j);
        if(j>0 && grid[i][j-1] == '1') flood(grid, i, j-1);
        if(j<cols-1 && grid[i][j+1] == '1') flood(grid, i,j+1);
    }

};