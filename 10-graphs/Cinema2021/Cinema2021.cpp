#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static const int MAX_SIZE = 1001;
unsigned int N, M;
bool visited[MAX_SIZE][MAX_SIZE];

bool check(int curX, int curY)
{
	return (curX > 0 && curY > 0 && curX <= N && curY <= M && !visited[curX][curY]);
}

void bfs(vector<pair<int, int>>& illStudents, int T)
{
	queue<pair<int, int>> infectedFromPrevIteration;
	queue<pair<int, int>> infectedFromCurrentIteration;
	int size = illStudents.size();
	for (int i = 0; i < size; i++)
	{
		visited[illStudents[i].first][illStudents[i].second] = true;
		infectedFromPrevIteration.push(illStudents[i]);
	}

	while (T--)
	{
		while (!infectedFromPrevIteration.empty())
		{
			int curX = infectedFromPrevIteration.front().first;
			int curY = infectedFromPrevIteration.front().second;
			infectedFromPrevIteration.pop();

			// bottom
			if (check(curX - 1, curY))
			{
				infectedFromCurrentIteration.push(make_pair(curX - 1, curY));
				visited[curX - 1][curY] = true;
			}
			// top
			if (check(curX + 1, curY))
			{
				infectedFromCurrentIteration.push(make_pair(curX + 1, curY));
				visited[curX + 1][curY] = true;
			}
			// left
			if (check(curX, curY - 1))
			{
				infectedFromCurrentIteration.push(make_pair(curX, curY - 1));
				visited[curX][curY - 1] = true;
			}
			// right
			if (check(curX, curY + 1))
			{
				infectedFromCurrentIteration.push(make_pair(curX, curY + 1));
				visited[curX][curY + 1] = true;
			}
		}

		infectedFromPrevIteration = infectedFromCurrentIteration;
		while (!infectedFromCurrentIteration.empty()) infectedFromCurrentIteration.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	unsigned int T, K;
	cin >> N >> M >> T >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			visited[i][j] = false;
		}
	}

	unsigned int AllStudents = N * M;
	int i, j;
	vector <pair<int, int>> illStudentsCoord;
	for (int k = 0; k < K; k++)
	{
		cin >> i >> j;
		illStudentsCoord.push_back(make_pair(i, j));
	}

	bfs(illStudentsCoord, T);

	unsigned int illStudents = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (visited[i][j] == true) illStudents++;
		}
	}

	printf("%u ", AllStudents - illStudents);

	return 0;
}