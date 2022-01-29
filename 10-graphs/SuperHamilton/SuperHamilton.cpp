#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX_SIZE = 25;
int rows, cols;
//char** matrix = new char* [rows];
bool visited[MAX_SIZE][MAX_SIZE];
char matrix[MAX_SIZE][MAX_SIZE];
int result;

void dfs(int i, int j, int path, int pathCount)
{
	visited[i][j] = 1;
	if (matrix[i][j] == '-')
	{
		path++;
	}

	if (matrix[i][j] == 'e')
	{
		if (path == pathCount)
		{
			result++;
		}

		visited[i][j] = false;
		return;
	}

	if (j >= 1 && !visited[i][j - 1] && matrix[i][j - 1] != 'x')
	{
		dfs(i, j - 1, path, pathCount);
	}

	if (j < cols - 1 && !visited[i][j + 1] && matrix[i][j + 1] != 'x')
	{
		dfs(i, j + 1, path, pathCount);
	}

	if (i >= 1 && !visited[i - 1][j] && matrix[i - 1][j] != 'x')
	{
		dfs(i - 1, j, path, pathCount);
	}

	if (i < rows - 1 && !visited[i + 1][j] && matrix[i + 1][j] != 'x')
	{
		dfs(i + 1, j, path, pathCount);
	}

	visited[i][j] = false;
}

int countDifferentPaths()
{
	int pathCount = 0;
	pair<int, int> startPoint;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] == '-')
			{
				pathCount++;
			}
			else if (matrix[i][j] == 's')
			{
				startPoint.first = i;
				startPoint.second = j;
			}
		}
	}

	dfs(startPoint.first, startPoint.second, 0, pathCount);

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> rows >> cols;

	for (int i = 0; i <= rows; i++)
	{
		for (int j = 0; j <= cols; j++)
		{
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> matrix[i][j];
		}
	}

	printf("%d", countDifferentPaths());

	return 0;
}

