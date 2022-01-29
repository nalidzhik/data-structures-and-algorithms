#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

struct Edge
{
	int from;
	int to;
	int speed;

	Edge(int from = 0, int to = 0, int speed = 0)
	{
		this->from = from;
		this->to = to;
		this->speed = speed;
	}

	bool operator <(const Edge& target)
	{
		return this->speed < target.speed;
	}
};

const int MAX_SIZE = 10001;
int N, M;
vector<Edge> edges;
int parent[MAX_SIZE];
int depth[MAX_SIZE];
int curDistance = INT_MAX;
int finalDistance = INT_MAX;
int curMax = INT_MIN;
int curMin = INT_MAX;
int finalMin = INT_MAX;
int finalMax = INT_MIN;

void init()
{
	for (int i = 0; i <= N; ++i)
	{
		parent[i] = i;
		depth[0] = 0;
	}
}

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
	int rootOne = Find(from);
	int rootTwo = Find(to);

	if (depth[rootOne] > depth[rootTwo])
	{
		parent[rootTwo] = rootOne;
	}
	else if (depth[rootTwo] > depth[rootOne])
	{
		parent[rootOne] = rootTwo;
	}
	else
	{
		parent[rootTwo] = rootOne;
		depth[rootOne]++;
	}
}

bool same(int a, int b)
{
	return Find(a) == Find(b);
}

void Kruskal()
{
	sort(edges.begin(), edges.end());

	for (int i = 0; i < M; i++)
	{
		init();
		int components = 1;

		Union(edges[i].from, edges[i].to);
		curMax = edges[i].speed;
		curMin = edges[i].speed;

		for (int j = i + 1; j < M; j++)
		{
			if (!same(edges[j].from, edges[j].to))
			{
				Union(edges[j].from, edges[j].to);
				curMax = max(curMax, edges[j].speed);

				components++;
			}

			if (components == N - 1)
			{
				break;
			}
		}

		curDistance = curMax - curMin;
		if (curDistance < finalDistance && components == N - 1)
		{
			finalDistance = curDistance;
			finalMin = curMin;
			finalMax = curMax;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	int from, to, speed;

	for (int i = 0; i < M; i++)
	{
		cin >> from >> to >> speed;
		Edge e = Edge(from, to, speed);
		edges.push_back(e);
	}

	Kruskal();

	printf("%d %d", finalMin, finalMax);

	return 0;
}