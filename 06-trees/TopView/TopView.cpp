#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

struct Node
{
    int data;
    int x;
    int y;
    Node* left;
    Node* right;

    Node(int _data, int _x, int _y) :data(_data), x(_x), y(_y), left(nullptr), right(nullptr) {}
};

void inOrder(Node* root, int width, int height, map<int, pair<int, int>>& Map)
{
    if (root == nullptr)
    {
        return;
    }

    inOrder(root->left, width - 1, height + 1, Map);

    // check if a particular horizontal level has been visited or not
    if (Map.find(width) == Map.end())
    {
        Map[width] = make_pair(root->data, height);
    }
    else if (Map[width].second > height)
    {
        Map[width] = make_pair(root->data, height);
    }

    inOrder(root->right, width + 1, height + 1, Map);
}

void topView(Node* root)
{
    if (root == nullptr)
    {
        return;
    }

    // map to store node at each vertical and horizontal level
    map<int, pair<int, int>> Map;

    inOrder(root, 0, 0, Map);

    for (auto child : Map)
    {
        cout << child.second.first << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Node*> tree;
    Node* root = new Node(0, 0, 0);
    tree.push_back(root);

    int leftChild, rightChild;
    for (int i = 0; i < N; i++)
    {
        cin >> leftChild >> rightChild;

        if (leftChild != -1)
        {
            Node* leftCh = new Node(leftChild, tree[i]->x - 1, tree[i]->y - 1);
            tree[i]->left = leftCh;
            tree.push_back(leftCh);
        }
        if (rightChild != -1)
        {
            Node* rightCh = new Node(rightChild, tree[i]->x + 1, tree[i]->y - 1);
            tree[i]->right = rightCh;
            tree.push_back(rightCh);
        }
    }

    topView(tree[0]);

    return 0;
}