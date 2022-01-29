#include <iostream>
#include <vector>

using namespace std;

void countChildren(vector<int>* tree, int* children, int root, int& count)
{
    if (tree[root].size() == 0)
    {
        count = 0;
        children[root] = count;
        return;
    }

    count = tree[root].size();
    for (auto child : tree[root])
    {
        int childrenCount = 0;
        countChildren(tree, children, child, childrenCount);
        count += childrenCount;
    }

    children[root] = count;
}

int main()
{
    const int N = 1000001;
    vector<int>* tree = new vector<int>[N];

    int n;
    cin >> n;

    int x, y;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x;
        cin >> y;

        tree[x].push_back(y);
    }

    int* children = new int[N];
    for (int i = 0; i < N; i++)
    {
        children[i] = -1;
    }

    int count = 0;
    countChildren(tree, children, 0, count);

    for (int i = 0; i < N; i++)
    {
        if (children[i] != -1)
        {
            cout << children[i] << " ";
        }
    }

    return 0;
}