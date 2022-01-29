#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, k;
    cin >> N >> k;

    int number;
    multimap <int, int> numbers;
    for (int i = 0; i < N; i++)
    {
        cin >> number;
        numbers.insert(pair <int, int>(i, number));
    }

    multimap<int, int>::iterator itrI = prev(numbers.end(), 1);
    vector<int> result;

    for (; itrI != numbers.begin(); itrI--)
    {
        int decreaseIndexJ = 1;
        bool isFoundIndexJ = false;
        int i = numbers.size() - (*itrI).first - 1;
        bool timeToBreak = false;

        while (i > -1)
        {
            if (prev(itrI, decreaseIndexJ) == numbers.begin())
            {
                timeToBreak = true;
            }

            multimap<int, int>::iterator itrJ = prev(itrI, decreaseIndexJ);
            if ((*itrJ).second < ((*itrI).second) && ((*itrI).second - (*itrJ).second <= k))
            {
                result.push_back((*itrJ).first);
                isFoundIndexJ = true;
                i--;
                break;
            }

            if (timeToBreak)
            {
                break;
            }

            decreaseIndexJ++;
        }

        if (!isFoundIndexJ)
        {
            result.push_back(-1);
        }
    }

    result.push_back(-1);

    int size = numbers.size() - 1;
    for (int i = size; i > -1; i--)
    {
        printf("%i ", result[i]);
    }

    return 0;
}