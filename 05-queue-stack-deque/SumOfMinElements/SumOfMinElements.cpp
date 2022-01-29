#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long int sumOfMin(vector<int>& elements, int d)
{
    long long int sum = 0;
    int n = elements.size();

    deque<int> deq;

    for (int i = 0; i < d; i++)
    {
        // only push the elements that may contribute to minimum
        while (!deq.empty() && elements[deq.back()] >= elements[i])
        {
            deq.pop_back();
        }
        deq.push_back(i);
    }

    sum += elements[deq.front()];

    for (int i = d; i < n; i++)
    {
        // remove the previous element (sliding window technique)
        while (!deq.empty() && deq.front() <= (i - d))
        {
            deq.pop_front();
        }

        while (!deq.empty() && elements[deq.back()] >= elements[i])
        {
            deq.pop_back();
        }

        deq.push_back(i);

        sum += elements[deq.front()];
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, d;
    cin >> N >> d;
    vector<int> elements;
    int element;

    for (int i = 0; i < N; i++)
    {
        cin >> element;
        elements.push_back(element);
    }

    cout << sumOfMin(elements, d) << '\n';

    return 0;
}
