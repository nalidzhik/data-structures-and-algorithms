#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int number)
{
    if (root == nullptr)
    {
        return new Node(number);
    }
    if (number < root->data)
    {
        root->left = insert(root->left, number);
    }
    else
    {
        root->right = insert(root->right, number);
    }

    return root;
}

Node* kthLargest(Node* root, int* i, int k)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    Node* left = kthLargest(root->right, i, k);
    if (left)
    {
        return left;
    }
    if (++ * i == k)
    {
        return root;
    }
    return kthLargest(root->left, i, k);
}

Node* findKthLargest(Node* root, int k)
{
    int i = 0;
    return kthLargest(root, &i, k);
}

Node* findMin(Node* root)
{
    Node* current = root;
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            root = temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            root = temp;
        }
        else
        {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, root->data);
        }
        return root;
    }

    return root;
}

void levelOrder(Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    queue < Node* > que;
    que.push(root);
    while (!que.empty())
    {
        Node* curr = que.front();
        que.pop();
        cout << curr->data << ' ';
        if (curr->left != nullptr)
        {
            que.push(curr->left);
        }
        if (curr->right != nullptr)
        {
            que.push(curr->right);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    Node* root = nullptr;
    int number;
    for (int i = 0; i < N; i++)
    {
        cin >> number;
        root = insert(root, number);
    }

    Node* node = findKthLargest(root, K);
    deleteNode(root, node->data);
    levelOrder(root);

    return 0;
}
