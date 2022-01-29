#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

static const int MAX_SIZE = 1000001;
vector<pair<int, int>> edges;
int parent[MAX_SIZE];
int N;

void init()
{
	for (int i = 0; i < N; i++)
	{
		parent[i] = i;
	}
}

int Find(int v)
{
	if (v == parent[v])
	{
		return v;
	}

	return Find(parent[v]);
}

void Union(int from, int to)
{
	int rootFrom = Find(from);
	int rootTo = Find(to);

	if (rootFrom != rootTo)
	{
		parent[rootTo] = rootFrom;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int M, Q, info, from, to;
	cin >> N >> M;
	init();

	for (int i = 0; i < M; i++)
	{
		cin >> from >> to;
		edges.push_back(make_pair(from, to));
	}

	for (int i = 0; i < M; i++)
	{
		Union(edges[i].first, edges[i].second);
	}

	cin >> Q;
	vector<int>answer;

	for (int i = 0; i < Q; i++)
	{
		cin >> info >> from >> to;
		if (info == 2)
		{
			Union(from, to);
		}
		else
		{
			int result = Find(from) == Find(to);
			answer.push_back(result);
		}
	}
	for (auto res : answer)
	{
		printf("%d", res);
	}

	return 0;
}

