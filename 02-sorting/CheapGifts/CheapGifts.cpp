#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void mergeSortedIntervals(vector<int>& v, int s, int m, int e)
{

    vector<int> temp;

    int i, j;
    i = s;
    j = m + 1;


    while (i <= m && j <= e)
    {

        if (v[i] <= v[j])
        {
            temp.push_back(v[i]);
            ++i;
        }
        else
        {
            temp.push_back(v[j]);
            ++j;
        }

    }

    while (i <= m) {
        temp.push_back(v[i]);
        ++i;
    }

    while (j <= e) {
        temp.push_back(v[j]);
        ++j;
    }

    for (int i = s; i <= e; ++i)
        v[i] = temp[i - s];

}

void mergeSort(vector<int>& v, int s, int e) {
    if (s < e)
    {
        int m = (s + e) / 2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        mergeSortedIntervals(v, s, m, e);
    }
}

int main()
{
    int N;
    cin >> N;

    vector<int> giftPrice;
    for (int i = 0; i < N; i++)
    {
        int price;
        cin >> price;
        giftPrice.push_back(price);
    }

    int employees;
    cin >> employees;

    mergeSort(giftPrice, 0, N - 1);

    long result = 0;
    if (employees < N)
    {
        for (int i = 0; i < employees; i++)
        {
            result += giftPrice[i];
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            result += giftPrice[i];
        }
        for (int i = 0; i < employees - N; i++)
        {
            result += giftPrice[i];
        }
    }

    cout << result << endl;

    return 0;
}