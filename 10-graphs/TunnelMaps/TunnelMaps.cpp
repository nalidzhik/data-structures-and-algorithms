#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Tunnel
{
	int to;
	int minWeight;
	int neededTime;

	Tunnel() = default;
	Tunnel(int to, int minWeight, int neededTime) : to(to), minWeight(minWeight), neededTime(neededTime) {}
};

int N, M, K;
int minCapacity = INT_MAX, maxCapacity = INT_MIN;
static const int MAX_SIZE = 100001;
int distan[MAX_SIZE];
bool visited[MAX_SIZE];
vector<Tunnel> adj[MAX_SIZE];

bool Dijkstra(int from, int to, int capacity)
{
	fill_n(distan, MAX_SIZE, INT_MAX);
	fill_n(visited, MAX_SIZE, false);

	priority_queue< pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > pq;
	pq.push(make_pair(0, from));
	distan[from] = 0;

	while (!pq.empty())
	{
		int current = pq.top().second;
		pq.pop();

		visited[current] = true;

		for (const auto& child : adj[current])
		{
			int v = child.to;
			int t = child.neededTime;
			int kg = child.minWeight;

			if (kg <= capacity && (visited[v] == false && distan[v] > distan[current] + t))
			{
				distan[v] = distan[current] + t;
				pq.push(make_pair(distan[v], v));
			}
		}
	}

	if (distan[to] == INT_MAX)
	{
		return false;
	}

	if (distan[to] < K)
	{
		return true;
	}

	return false;
}

int binarySearch(int from, int to)
{
	int left = 1, right = maxCapacity;
	int mid = 0;
	int result = INT_MAX;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (Dijkstra(from, to, mid))
		{
			right = mid - 1;
			result = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	if (result == INT_MAX)
	{
		return -1;
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	int u, v, c, t;

	for (int i = 0; i < M; i++)
	{
		Tunnel tunnel;
		cin >> u >> v >> c >> t;
		tunnel.to = v - 1;
		tunnel.minWeight = c;
		tunnel.neededTime = t;

		if (c < minCapacity)
		{
			minCapacity = c;
		}

		if (c > maxCapacity)
		{
			maxCapacity = c;
		}

		adj[--u].push_back(tunnel);
	}

	int result = binarySearch(0, N - 1);
	printf("%d", result);

	return 0;
}
