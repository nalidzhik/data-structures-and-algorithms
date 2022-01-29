#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

const int MAX_SIZE = 1000001;
int N;
vector<int> graph[MAX_SIZE];
int depth[MAX_SIZE]{ 0 };
vector<int> ans;

void minDepth(int v)
{
	queue<int> qu;

	for (int i = 0; i < N; i++)
	{
		if (depth[i] == 1)
		{
			qu.push(i);
		}
	}

	while (N > 2)
	{
		int size = qu.size();
		N -= size;

		for (int i = 0; i < size; i++)
		{
			int x = qu.front();
			qu.pop();

			for (auto neighbour : graph[x])
			{
				depth[neighbour]--;
				if (depth[neighbour] == 1)
				{
					qu.push(neighbour);
				}
			}
		}
	}

	while (!qu.empty())
	{
		ans.push_back(qu.front());
		qu.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	int from, to;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
		depth[from]++;
		depth[to]++;
	}

	minDepth(0);

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}

	return 0;
}