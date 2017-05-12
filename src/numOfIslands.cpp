#include <iostream>
#include <vector>

using namespace std;

void search(vector<vector<char>> &grid,int i,int j, vector<vector<bool>> &visited) {
	visited[i][j] = true;
	if (((i + 1) < grid.size()) && (grid[i + 1][j] == '1') && (visited[i + 1][j] == false))
	{
		search(grid, (i + 1), j, visited);
	}
	if (((i - 1) >=0) && (grid[i - 1][j] == '1') && (visited[i - 1][j] == false))
	{
		search(grid, (i - 1), j, visited);
	}
	if (((j + 1) < grid[0].size()) && (grid[i][j+1] == '1') && (visited[i][j+1] == false))
	{
		search(grid, i, (j+1), visited);
	}
	if (((j - 1) >=0) && (grid[i][j - 1] == '1') && (visited[i][j - 1] == false))
	{
		search(grid, i, (j - 1), visited);
	}

}

int countIslands(vector<vector<char>> &grid) {
	int row = grid.size();
	int col = grid[0].size();
	int count = 0;
	vector<vector<bool>> visited(row, vector<bool>(col, false));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if ((grid[i][j] == '1') && (visited[i][j] == false))
			{
				search(grid, i, j,visited);
				count++;
			}
		}
	}
	return count;
}

int main() {
	vector < vector<char>> grid = {{'1','1','1','0','1'},{'1','1','0','0','0'},{'0','1','0','1','1'}};
	int result = countIslands(grid);
	cout << result;
	return 0;
}