#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX_SIZE = 1000000;
int degree[MAX_SIZE];
int N, M;
vector<string> ans;
vector<int> graph[MAX_SIZE];
bool visited[MAX_SIZE];

void dfs(int u)
{
	visited[u] = true;

	for (auto v : graph[u])
	{
		if (!visited[v])
		{
			dfs(v);
		}
	}
}

bool isConnected()
{
	dfs(0);
	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int queries;
	cin >> queries;

	int from, to;
	while (queries--)
	{
		int numberOfOddDegree = 0;
		cin >> N >> M;

		for (int i = 0; i < MAX_SIZE; i++)
		{
			degree[i] = 0;
		}

		while (M)
		{
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
			degree[to]++;
			degree[from]++;
			M--;
		}

		for (int i = 0; i < MAX_SIZE; i++)
		{
			if (degree[i] % 2 != 0)
			{
				numberOfOddDegree++;
			}
		}

		if (isConnected() || numberOfOddDegree == 0)
		{
			if (numberOfOddDegree == 0)
			{
				ans.push_back("ecycle\n");
			}
			else if (numberOfOddDegree == 0 || numberOfOddDegree == 2)
			{
				ans.push_back("epath\n");
			}
			else
			{
				ans.push_back("none\n");
			}
		}
		else
		{
			ans.push_back("none\n");
		}

		fill_n(visited, MAX_SIZE, false);
		for (int i = 0; i < MAX_SIZE; i++)
		{
			graph[i].clear();
		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		printf("%s", ans[i].c_str());
	}

	return 0;
}