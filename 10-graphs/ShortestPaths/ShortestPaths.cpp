#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

static const int MAX_SIZE = 1000001;
pair<int, int> distan[MAX_SIZE];
vector<pair<int, int>>adjacencyList[MAX_SIZE];
const int modulo = 1000000007;

void shortestPathDijkstra(int v)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		distan[i].first = INT_MAX;
		distan[i].second = 0;
	}

	distan[v].second = 1;
	distan[v].first = 0;

	priority_queue< pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > pq;
	pq.push(make_pair(0, v));

	while (!pq.empty())
	{
		int current = pq.top().second;
		int costToCurrent = pq.top().first;
		pq.pop();

		for (pair<int, int> neighbour : adjacencyList[current])
		{
			int child = neighbour.first;
			int costToChildOfCurrent = neighbour.second;

			if (distan[child].first > costToCurrent + costToChildOfCurrent)
			{
				distan[child].first = costToCurrent + costToChildOfCurrent;
				distan[child].second = distan[current].second;
				distan[child].second %= modulo;
				pq.push(make_pair(costToChildOfCurrent + costToCurrent, child));
			}
			else if (distan[child].first == costToCurrent + costToChildOfCurrent)
			{
				distan[child].second += distan[current].second;
				distan[child].second %= modulo;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	int ui, vi, ci;
	for (int i = 0; i < M; i++)
	{
		cin >> ui >> vi >> ci;
		adjacencyList[ui].push_back(make_pair(vi, ci));
	}

	shortestPathDijkstra(1);

	if (distan[N].second)
	{
		printf("%d %d", distan[N].first, distan[N].second);
	}
	else
	{
		printf("-1 0");
	}

	return 0;
}
