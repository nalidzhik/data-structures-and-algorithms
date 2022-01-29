#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

struct Request
{
    double s;
    double p;
    unsigned int index;

    Request() : Request(0, 0) {}
    Request(double s, double p)
    {
        this->s = s;
        this->p = p;
    }

    unsigned int findIndex(vector<double>& elements)
    {
        return this->index = upper_bound(elements.begin(), elements.end(), p) - elements.begin() - 1;
    }

    unsigned int countElements(vector<double>& sumElements, vector<double>& elements)
    {
        unsigned int index = findIndex(elements);
        unsigned int idx = elements.size() - 1 - index;
        double sum = s;

        if (s < elements[index])
        {
            return 0;
        }

        if (idx != 0)
        {
            sum += sumElements[idx - 1];
        }

        if (sum >= sumElements[sumElements.size() - 1])
        {
            return index + 1;
        }

        unsigned int upper = (upper_bound(sumElements.begin() + idx, sumElements.end(), sum)) - (sumElements.begin() + idx) - 1;
        return upper + 1;
    }

};

int main()
{
    // for faster result + printf
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int N, Q;
    cin >> N >> Q;
    vector<double> elements;
    vector<Request> requests;
    for (int i = 0; i < N; i++)
    {
        double num;
        cin >> num;
        elements.push_back(num);
    }
    for (int i = 0; i < Q; i++)
    {
        double s, p;
        cin >> s >> p;
        Request request = Request(s, p);
        requests.push_back(request);
    }

    stable_sort(elements.begin(), elements.end());

    vector<double> sumElements;
    double sumCurrent = 0;
    unsigned int size = N - 1;


    for (int i = size; i > -1; i--)
    {
        sumCurrent += elements[i];
        sumElements.push_back(sumCurrent);
    }

    for (int i = 0; i < requests.size(); i++)
    {
        printf("%d \n", requests[i].countElements(sumElements, elements));
    }

    return 0;
}