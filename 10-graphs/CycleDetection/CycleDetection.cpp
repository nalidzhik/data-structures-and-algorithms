#include <iostream>
#include <vector>

using namespace std;

static const int N = 1000000;
vector<int> adj[N];
int visited[N]{ 0 };

bool hasCycle(int s)
{
	visited[s] = 1;

	for (int v : adj[s])
	{
		if (visited[v] == 0)
		{
			if (hasCycle(v))
			{
				return true;
			}
		}

		else if (visited[v] == 1)
		{
			return true;
		}
	}

	visited[s] = 2;

	return false;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int Q, E, Start, End;
	cin >> Q;

	vector<pair<int, int>> edges;

	while (Q--)
	{
		cin >> E;
		bool isCycle = false;

		for (int i = 0; i < E; i++)
		{
			cin >> Start >> End;
			edges.push_back(make_pair(Start, End));
		}

		for (int i = 0; i < E; i++)
		{
			adj[edges[i].first].push_back(edges[i].second);
		}

		for (int i = 0; i < E; i++)
		{
			if (hasCycle(i))
			{
				isCycle = true;
				break;
			}
		}

		if (isCycle)
		{
			printf("1 ");
		}
		else
		{
			printf("0 ");
		}

		fill_n(visited, N, 0);
		edges.clear();
		for (int i = 0; i < N; i++)
		{
			adj[i].clear();
		}

	}

	return 0;
}