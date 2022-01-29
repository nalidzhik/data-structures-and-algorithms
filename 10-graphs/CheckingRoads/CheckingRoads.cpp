#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int graph[1000][1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    int x, y, w;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> w;
        graph[x][y] = w;
        graph[y][x] = w;
    }

    cin >> K >> x;
    long long int res = 0;

    for (int i = 0; i < K - 1; i++)
    {
        cin >> y;
        if (graph[x][y])
        {
            res += graph[x][y];
        }
        else
        {
            cout << -1;
            return 0;
        }
        x = y;
    }

    cout << res;

    return 0;
}
