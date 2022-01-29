#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

static const int MAX_SIZE = 100001;
vector<pair<int, int>> adj[MAX_SIZE];
int distan[MAX_SIZE];
int N;

void Dijkstra(int v)
{
	fill_n(distan, MAX_SIZE, INT_MAX);

	distan[v] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(v, 0));

	while (!pq.empty())
	{
		int current = pq.top().first;
		pq.pop();

		for (pair<int, int> neighbour : adj[current])
		{
			int child = neighbour.first;
			int costToChildOfCurrent = neighbour.second;

			if (distan[child] > distan[current] + costToChildOfCurrent)
			{
				distan[child] = distan[current] + costToChildOfCurrent;
				pq.push(make_pair(child, distan[child]));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// N - numberOfVerices, M - numberOfEdges, K - numberOfElementsFromT (the others are from S), Q - numberOfRequests ;
	int M, K, Q;
	cin >> N >> M;

	int from, to, weight;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to >> weight;
		adj[from].push_back(make_pair(to, weight));
		adj[to].push_back(make_pair(from, weight));
	}

	cin >> K;
	int elementFromT;
	for (int i = 0; i < K; i++)
	{
		cin >> elementFromT;
		adj[elementFromT].push_back(make_pair(N, 0));
		adj[N].push_back(make_pair(elementFromT, 0));
	}

	cin >> Q;
	int request;
	Dijkstra(N);

	vector<int> result;
	for (int i = 0; i < Q; i++)
	{
		cin >> request;
		result.push_back(distan[request]);
	}

	for (int i = 0; i < Q; i++)
	{
		printf("%d\n", result[i]);
	}

	return 0;
}

