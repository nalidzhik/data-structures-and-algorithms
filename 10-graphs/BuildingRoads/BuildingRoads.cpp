#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct Edge
{
	int from;
	int to;
	long long int cost;
	long long int profit;
	int index;

	Edge(int from = 0, int to = 0, long long int cost = 0, long long int profit = 0, int index = 0)
	{
		this->from = from;
		this->to = to;
		this->cost = cost;
		this->index = index;
		this->profit = profit;
	}

	bool operator <(const Edge& target)
	{
		if (this->cost == target.cost)
		{
			return this->profit >= target.profit;
		}
		return this->cost < target.cost;
	}
};

static const int MAX_SIZE = 200001;
int N, M;
vector<Edge> edges;
int parent[MAX_SIZE];
int depth[MAX_SIZE];
vector<Edge> mst[MAX_SIZE];
vector<int> answer;

int Find(int node)
{
	if (node == parent[node])
	{
		return node;
	}

	return Find(parent[node]);
}

void Union(int from, int to)
{
	if (depth[from] > depth[to])
	{
		parent[to] = from;
	}
	else if (depth[to] > depth[from])
	{
		parent[from] = to;
	}
	else
	{
		parent[to] = from;
		depth[from]++;
	}
}

void kruskal()
{
	int components = N;

	sort(edges.begin(), edges.end());

	for (int i = 0; i < N; i++)
	{
		parent[i] = i;
		depth[i] = 0;
	}

	for (Edge e : edges)
	{
		int root1 = Find(e.from);
		int root2 = Find(e.to);

		if (root1 != root2)
		{
			Union(root1, root2);

			mst[e.from].push_back(e);
			mst[e.to].push_back(e);

			components--;

			answer.push_back(e.index);
		}

		if (components == 1)
		{
			break;
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	int from, to;
	long long int c1, c2;
	
	for (int i = 1; i <= M; i++)
	{
		cin >> from >> to >> c1 >> c2;
		Edge e = Edge(from, to, c1, c2, i);
		edges.push_back(e);
	}

	kruskal();
	for (int i = 0; i < N - 1; i++)
	{
		printf("%d\n", answer[i]);
	}

	return 0;
}

